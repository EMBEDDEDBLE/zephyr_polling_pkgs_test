#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <windows.h>

#include "chipset_interface.h"
#include "windows_driver_libusb.h"
#include "windows_log_impl.h"
#include "windows_storage_kv_impl.h"
#include "windows_timer_impl.h"

#include "base/types.h"
#include "utils/spool.h"
#include <logging/bt_log_impl.h>
#include <drivers/hci_driver.h>
#include "host/hci_core.h"

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>

extern void bt_ready(int err);
extern void app_polling_work(void);

int main(void)
{
    int err = 0;

    bt_log_impl_register(bt_log_impl_local_instance());
    if (usb_open_device() < 0)
    {
        return -1;
    }
    bt_hci_chipset_driver_register(chipset_local_instance());
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

        extern void libusb_main_loop(void);
        libusb_main_loop();
    }

    return (err);
}