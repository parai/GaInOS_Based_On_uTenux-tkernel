#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/* ################ Can General ################ */
#define CAN_DEV_ERROR_DETECT STD_ON
#define CAN_VERSION_INFO_API STD_OFF
#define CAN_TIMEOUT_DURATION 10 /* ms */

/* Number of controller configs */
#define CAN_CTRL_CONFIG_CNT 3

typedef enum {
	CAN_CTRL_0_vCanHohTx,
	CAN_CTRL_1_vCanHohTx,
	CAN_CTRL_4_vCanHohTx,
	NUM_OF_HTHS
} Can_Arc_HTHType;

typedef enum {
	CAN_CTRL_0_vCanHohRx,
	CAN_CTRL_1_vCanHohRx,
	CAN_CTRL_4_vCanHohRx,
	NUM_OF_HRHS
} Can_Arc_HRHType;

IMPORT const Can_ConfigType Can_ConfigData;
#endif /* CAN_CFG_H_ */

