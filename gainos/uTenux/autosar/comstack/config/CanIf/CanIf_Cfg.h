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
#define CANIF_ARC_RUNTIME_PDU_CONFIGURATION False   // Not supported
#define CANIF_CANPDUID_READDATA_API         STD_OFF   // Not supported
#define CANIF_READRXPDU_NOTIF_STATUS_API    STD_OFF   // Not supported

#define USE_PDUR

/* Tx PduId For CanIF */
#define vCanIf_Channel0_vCanIf_Hth0_vEcuC_Pdu0		0
#define vCanIf_Channel0_vCanIf_Hth0_vEcuC_Pdu1		1
#define vCanIf_Channel0_vCanIf_Hth1_vEcuC_Pdu0		2
#define vCanIf_Channel1_vCanIf_Hth0_vEcuC_Pdu1		3
#define vCanIf_Channel4_vCanIf_Hth0_vEcuC_Pdu4		4
/* Rx PduId For CanIF */
#define vCanIf_Channel0_vCanIf_Hrh0_vEcuC_Pdu0		0
#define vCanIf_Channel0_vCanIf_Hrh1_vEcuC_Pdu0		1
#define vCanIf_Channel1_vCanIf_Hrh0_vEcuC_Pdu1		2
#define vCanIf_Channel4_vCanIf_Hrh0_vEcuC_Pdu4		3
// Identifiers for the elements in CanIfControllerConfig[]
// This is the ConfigurationIndex in CanIf_InitController()
typedef enum {
	vCanIf_Channel0_CONFIG_0,
	vCanIf_Channel1_CONFIG_0,
	vCanIf_Channel4_CONFIG_0,
	CANIF_CHANNEL_CONFIGURATION_CNT
}CanIf_Arc_ConfigurationIndexType;

typedef enum {
	vCanIf_Channel0,
	vCanIf_Channel1,
	vCanIf_Channel4,
	CANIF_CHANNEL_CNT
}CanIf_Arc_ChannelIdType;

#include "CanIf_ConfigTypes.h"

IMPORT CanIf_ConfigType CanIf_Config;

#endif

