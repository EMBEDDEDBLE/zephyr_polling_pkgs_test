#define CONFIG_BT 1
#define CONFIG_BT_LOG_LEVEL_INF 1
#define CONFIG_BT_LOG_LEVEL 3
#define CONFIG_BT_PERIPHERAL 1
#define CONFIG_BT_BROADCASTER 1
#define CONFIG_BT_CONN 1
#define CONFIG_BT_MAX_CONN 1
#define CONFIG_BT_CONN_TX 1
#define CONFIG_BT_PHY_UPDATE 1
#define CONFIG_BT_DATA_LEN_UPDATE 1
#define CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC 1000
#define CONFIG_SYS_CLOCK_TICKS_PER_SEC 1000
#define CONFIG_SYS_CLOCK_MAX_TIMEOUT_DAYS 365
#define CONFIG_BT_BUF_ACL_TX_SIZE 251
#define CONFIG_BT_BUF_ACL_TX_COUNT 3
#define CONFIG_BT_BUF_ACL_RX_SIZE 255
#define CONFIG_BT_BUF_ACL_RX_COUNT 6
#define CONFIG_BT_BUF_EVT_RX_SIZE 68
#define CONFIG_BT_BUF_EVT_RX_COUNT 10
#define CONFIG_BT_BUF_EVT_DISCARDABLE_SIZE 255
#define CONFIG_BT_BUF_EVT_DISCARDABLE_COUNT 3
#define CONFIG_BT_BUF_CMD_TX_SIZE 255
#define CONFIG_BT_BUF_CMD_TX_COUNT 6
#define CONFIG_BT_RPA 1
#define CONFIG_BT_ASSERT 1
#define CONFIG_BT_ASSERT_VERBOSE 1
#define CONFIG_BT_DEBUG 1
#define CONFIG_BT_DEBUG_LOG 1
#define CONFIG_BT_HCI_RESERVE 0
#define CONFIG_BT_RX_PRIO 8
#define CONFIG_BT_DRIVER_RX_HIGH_PRIO 6
#define CONFIG_BT_HOST_CRYPTO 1
#define CONFIG_BT_HOST_CRYPTO_PRNG 1
#define CONFIG_BT_LIM_ADV_TIMEOUT 30
#define CONFIG_BT_CONN_TX_MAX 3
#define CONFIG_BT_AUTO_PHY_UPDATE 1
#define CONFIG_BT_AUTO_DATA_LEN_UPDATE 1
#define CONFIG_BT_SMP 1
#define CONFIG_BT_BONDABLE 1
#define CONFIG_BT_SMP_ENFORCE_MITM 1
#define CONFIG_BT_SMP_MIN_ENC_KEY_SIZE 7
#define CONFIG_BT_L2CAP_TX_BUF_COUNT 3
#define CONFIG_BT_L2CAP_TX_FRAG_COUNT 0
#define CONFIG_BT_L2CAP_TX_MTU 247
#define CONFIG_BT_GATT_FIXED_SERVICES_SIZE 7
#define CONFIG_BT_ATT_PREPARE_COUNT 0
#define CONFIG_BT_ATT_RETRY_ON_SEC_ERR 1
#define CONFIG_BT_GATT_AUTO_SEC_REQ 1
#define CONFIG_BT_GATT_CLIENT 1
#define CONFIG_BT_GATT_READ_MULTIPLE 1
#define CONFIG_BT_GATT_READ_MULT_VAR_LEN 1
#define CONFIG_BT_GAP_AUTO_UPDATE_CONN_PARAMS 1
#define CONFIG_BT_GAP_PERIPHERAL_PREF_PARAMS 1
#define CONFIG_BT_PERIPHERAL_PREF_MIN_INT 24
#define CONFIG_BT_PERIPHERAL_PREF_MAX_INT 40
#define CONFIG_BT_PERIPHERAL_PREF_LATENCY 0
#define CONFIG_BT_PERIPHERAL_PREF_TIMEOUT 42
#define CONFIG_BT_MAX_PAIRED 1
#define CONFIG_BT_CREATE_CONN_TIMEOUT 3
#define CONFIG_BT_CONN_PARAM_UPDATE_TIMEOUT 5000
#define CONFIG_BT_DEVICE_NAME "Zephyr GATT Write"
#define CONFIG_BT_DEVICE_APPEARANCE 0
#define CONFIG_BT_ID_MAX 1
#define CONFIG_BT_ECC 1
#define CONFIG_BT_COMPANY_ID 0x05F1
