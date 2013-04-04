
#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_

#include "Can.h"


#define CANIF_VERSION_INFO_API              STD_ON
#define CANIF_DEV_ERROR_DETECT			    STD_OFF
#define CANIF_DLC_CHECK                     STD_ON
#define CANIF_ARC_RUNTIME_PDU_CONFIGURATION	STD_OFF
#define CANIF_MULITPLE_DRIVER_SUPPORT       STD_OFF  // Not supported
#define CANIF_READRXPDU_DATA_API			STD_OFF  // Not supported
#define CANIF_READRXPDU_NOTIFY_STATUS_API	STD_OFF  // Not supported
#define CANIF_READTXPDU_NOTIFY_STATUS_API	STD_OFF  // Not supported
#define CANIF_SETDYNAMICTXID_API            STD_OFF  // Not supported
#define CANIF_WAKEUP_EVENT_API			    STD_OFF  // Not supported
#define CANIF_TRANSCEIVER_API               STD_OFF  // Not supported
#define CANIF_TRANSMIT_CANCELLATION         STD_OFF  // Not supported

#define CANIF_CANPDUID_READDATA_API         STD_OFF
#define CANIF_READRXPDU_NOTIF_STATUS_API    STD_OFF

#define CANIF_TX_PDU_ID_PDU_CAN0		0
#define CANIF_TX_PDU_ID_PDU_CAN1		1

#define CANIF_RX_PDU_ID_PDU_CAN0		0
#define CANIF_RX_PDU_ID_PDU_CAN1		1

#define USE_PDUR

// Identifiers for the elements in CanIfControllerConfig[]
// This is the ConfigurationIndex in CanIf_InitController()
typedef enum {
	CANIF_CAN_CHL0_CONFIG_0,
	CANIF_CAN_CHL1_CONFIG_0,
	CANIF_CHANNEL_CONFIGURATION_CNT
} CanIf_Arc_ConfigurationIndexType;

typedef enum {
	CANIF_CAN_CHL0,
	CANIF_CAN_CHL1,
	CANIF_CHANNEL_CNT
} CanIf_Arc_ChannelIdType;

#define CANIF_CONTROLLER_ID_CAN0	CANIF_CAN_CHL0
#define CANIF_CONTROLLER_ID_CAN1	CANIF_CAN_CHL1


#include "CanIf_ConfigTypes.h"


IMPORT CanIf_ConfigType CanIf_Config;

#endif

