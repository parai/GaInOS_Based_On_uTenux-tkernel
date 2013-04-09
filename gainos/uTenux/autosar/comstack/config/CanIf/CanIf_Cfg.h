#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_

#include "Can.h"

#define CANIF_VERSION_INFO_API   STD_ON
#define CANIF_DEV_ERROR_DETECT   STD_ON
#define CANIF_DLC_CHECK          STD_ON
#define CANIF_MULITPLE_DRIVER_SUPPORT       STD_OFF   // Not supported
#define CANIF_READRXPDU_DATA_API			 STD_OFF   // Not supported
#define CANIF_READRXPDU_NOTIFY_STATUS_API	 STD_OFF   // Not supported
#define CANIF_READTXPDU_NOTIFY_STATUS_API	 STD_OFF   // Not supported
#define CANIF_SETDYNAMICTXID_API            STD_OFF   // Not supported
#define CANIF_WAKEUP_EVENT_API			     STD_OFF   // Not supported
#define CANIF_TRANSCEIVER_API               STD_OFF   // Not supported
#define CANIF_TRANSMIT_CANCELLATION         STD_OFF   // Not supported
#define CANIF_ARC_RUNTIME_PDU_CONFIGURATION STD_OFF   // Not supported
#define CANIF_CANPDUID_READDATA_API         STD_OFF   // Not supported
#define CANIF_READRXPDU_NOTIF_STATUS_API    STD_OFF   // Not supported

#define USE_PDUR
#define USE_COM

/* Tx PduId For CanIF */
#define TX_vEcuC_Pdu0		0
#define TX_vEcuC_Pdu1		1
#define TX_vEcuC_Pdu2		2
/* Rx PduId For CanIF */
#define RX_vEcuC_Pdu0		0
#define RX_vEcuC_Pdu1		1
#define RX_vEcuC_Pdu2		2
// Identifiers for the elements in CanIfControllerConfig[]
// This is the ConfigurationIndex in CanIf_InitController()
typedef enum {
	vCanIf_Channel0_CONFIG_0,
	vCanIf_Channel1_CONFIG_0,
	vCanIf_Channel2_CONFIG_0,
	CANIF_CHANNEL_CONFIGURATION_CNT
}CanIf_Arc_ConfigurationIndexType;

typedef enum {
	vCanIf_Channel0,
	vCanIf_Channel1,
	vCanIf_Channel2,
	CANIF_CHANNEL_CNT
}CanIf_Arc_ChannelIdType;

#include "CanIf_ConfigTypes.h"

IMPORT CanIf_ConfigType CanIf_Config;

#endif

