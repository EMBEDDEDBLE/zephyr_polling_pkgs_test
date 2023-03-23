#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <rtthread.h>

#include "rtthread_driver_serial.h"

#include "chipset_interface.h"
#include "platform_interface.h"

#include "base/types.h"
#include "utils/spool.h"
#include <logging/bt_log_impl.h>
#include <drivers/hci_driver.h>
#include "host/hci_core.h"

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>

extern void bt_ready(int err);
extern void app_polling_work(void);

int bt_init_hci_driver(void)
{
    bt_uart_interface_t *p_interface = NULL;
    uint8_t com_num;
    // accept config from command line
    // if (argc > 1)
    // {
    //     // COM number
    //     com_num = strtol(argv[1], NULL, 0);

    //     bt_uart_interface_t tmp = {0, 0, 0, 0, 0};

    //     if (argc == 2)
    //     {
    //     }
    //     else if (argc == 7)
    //     {
    //         tmp.rate = strtol(argv[2], NULL, 0);
    //         tmp.databits = strtol(argv[3], NULL, 0);
    //         tmp.stopbits = strtol(argv[4], NULL, 0);
    //         tmp.parity = strtol(argv[5], NULL, 0);
    //         tmp.flowcontrol = strtol(argv[6], NULL, 0);

    //         p_interface = &tmp;
    //     }
    //     else
    //     {
    //         printk("Error, input params length error.");
    //         return -1;
    //     }
    // }
    // else
    // {
    //     printk("Error, must input COM number.");
    //     return -1;
    // }

    // Get Input config.
    if (p_interface == NULL)
    {
        p_interface = (bt_uart_interface_t *)bt_chipset_get_uart_interface();
    }

    if (p_interface == NULL)
    {
        printk("Error, uart params not set.");
        return -1;
    }

    if (bt_hci_init_serial_device(com_num, p_interface->rate, p_interface->databits, p_interface->stopbits,
                           p_interface->parity, p_interface->flowcontrol) < 0)
    {
        printk("Error, uart open failed.");
        return -1;
    }

    return 0;
}


void zephyr_polling_main(void* parameter)
{
    int err = 0;

    bt_log_impl_register(bt_log_impl_local_instance());

    if (bt_init_hci_driver() < 0)
    {
        return;
    }
    bt_hci_chipset_driver_register(bt_hci_chipset_impl_local_instance());
    bt_storage_kv_register(bt_storage_kv_impl_local_instance());
    bt_timer_impl_local_init();

    /* Initialize the Bluetooth Subsystem */
    err = bt_enable(bt_ready);

#if defined(CONFIG_BT_MONITOR_SLEEP)
    bt_init_monitor_sleep();
#endif

    while (1)
    {
#if defined(CONFIG_BT_MONITOR_SLEEP)
        if (!bt_check_is_in_sleep())
        {
            bt_polling_work();

            if (bt_is_ready() && bt_check_allow_sleep())
            {
                bt_sleep_prepare_work();
            }
        }
#else
        bt_polling_work();
#endif

        app_polling_work();

        extern void bt_hci_h4_polling(void);
        bt_hci_h4_polling();

        rt_thread_yield();
        //rt_thread_sleep(1);
    }
}

static struct rt_thread zephyr_polling_main_thread;

static rt_uint8_t zephyr_polling_main_thread_stack[4096];

int zephyr_polling_init(void)
{
    rt_thread_init(&zephyr_polling_main_thread,
                   "zephyr_polling_main",
                   zephyr_polling_main,
                   RT_NULL,
                   &zephyr_polling_main_thread_stack[0],
                   sizeof(zephyr_polling_main_thread_stack),
                   6,
                   20);

    rt_thread_startup(&zephyr_polling_main_thread);

    return 0;
}
// INIT_APP_EXPORT(zephyr_polling_init);
MSH_CMD_EXPORT(zephyr_polling_init, "zephyr_polling start");
