#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/* ################ Can General ################ */
#define CAN_DEV_ERROR_DETECT STD_ON
#define CAN_VERSION_INFO_API STD_OFF
#define CAN_TIMEOUT_DURATION 10 /* ms */

/* Number of controller configs */
#define CAN_CTRL_CONFIG_CNT 5

typedef enum {
	CAN_CTRL_0_vCanHoh1,
	CAN_CTRL_1_vCanHoh1,
	CAN_CTRL_2_vCanHoh1,
	CAN_CTRL_3_vCanHoh1,
	CAN_CTRL_4_vCanHoh1,
	NUM_OF_HTHS
} Can_Arc_HTHType;

typedef enum {
	CAN_CTRL_0_vCanHoh0,
	CAN_CTRL_1_vCanHoh0,
	CAN_CTRL_2_vCanHoh0,
	CAN_CTRL_3_vCanHoh0,
	CAN_CTRL_4_vCanHoh0,
	NUM_OF_HRHS
} Can_Arc_HRHType;

IMPORT const Can_ConfigType Can_ConfigData;
#endif /* CAN_CFG_H_ */

