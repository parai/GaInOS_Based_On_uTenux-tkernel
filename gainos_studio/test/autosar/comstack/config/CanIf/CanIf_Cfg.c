#include "CanIf.h"
#if defined(USE_CANTP)
#include "CanTp.h"
#include "CanTp_Cbk.h"
#endif
#if defined(USE_J1939TP)
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
#endif
#if defined(USE_PDUR)
#include "PduR.h"
#endif
#if defined(USE_CANNM)
#include "CanNm_Cbk.h"
#endif
#include <stdlib.h>

// Imported structs from Can_PBcfg.c
IMPORT const Can_ControllerConfigType Can_ControllerCfgData[];
IMPORT const Can_ConfigSetType Can_ConfigSetData;

extern void CanIf_UserRxIndication(uint8 channel, PduIdType pduId, const uint8 *sduPtr,uint8 dlc, Can_IdType canId);
void CanIf_User_BusoffNotification(uint8 Controller){}
void CanIf_User_ErrorNotification(uint8 Controller,Can_Arc_ErrorType Error){}

// Contains the mapping from CanIf-specific Channels to Can Controllers
const Can_ControllerIdType CanIf_Arc_ChannelToControllerMap[CANIF_CHANNEL_CNT] = {
	CAN_CTRL_0,	/* vCanIf_Channel0 */
	CAN_CTRL_1,	/* vCanIf_Channel1 */
	CAN_CTRL_4,	/* vCanIf_Channel4 */
};

const uint8 CanIf_Arc_ChannelDefaultConfIndex[CANIF_CHANNEL_CNT] = {
	vCanIf_Channel0_CONFIG_0,
	vCanIf_Channel1_CONFIG_0,
	vCanIf_Channel4_CONFIG_0,
};

// Container that gets slamed into CanIf_InitController()
// Inits ALL controllers
// Multiplicity 1/*/**
const CanIf_ControllerConfigType CanIfControllerConfig[] = {
	// This is the ConfigurationIndex in CanIf_InitController()
	{
		/*WakeupSupport =*/ CANIF_WAKEUP_SUPPORT_NO_WAKEUP,
		/*CanIfControllerIdRef =*/ vCanIf_Channel0,
		/*CanIfDriverNameRef =*/ "FLEXCAN",  // Not used
		/*CanIfInitControllerRef =*/ &Can_ControllerCfgData[INDEX_OF_CAN_CTRL_0],
	},
	{
		/*WakeupSupport =*/ CANIF_WAKEUP_SUPPORT_NO_WAKEUP,
		/*CanIfControllerIdRef =*/ vCanIf_Channel1,
		/*CanIfDriverNameRef =*/ "FLEXCAN",  // Not used
		/*CanIfInitControllerRef =*/ &Can_ControllerCfgData[INDEX_OF_CAN_CTRL_1],
	},
	{
		/*WakeupSupport =*/ CANIF_WAKEUP_SUPPORT_NO_WAKEUP,
		/*CanIfControllerIdRef =*/ vCanIf_Channel4,
		/*CanIfDriverNameRef =*/ "FLEXCAN",  // Not used
		/*CanIfInitControllerRef =*/ &Can_ControllerCfgData[INDEX_OF_CAN_CTRL_4],
	},
};

// Function callbacks for higher layers
const CanIf_DispatchConfigType CanIfDispatchConfig =
{
	/*CanIfBusOffNotification =*/ CanIf_User_BusoffNotification,
	/*CanIfWakeUpNotification =*/ NULL,        // Not used
	/*CanIfWakeupValidNotification =*/ NULL,   // Not used
	/*CanIfErrorNotificaton =*/ CanIf_User_ErrorNotification,
};

// Data for init configuration CanIfInitConfiguration

const CanIf_HthConfigType CanIfHthConfigData_vCanIf_Channel0[]=
{
	{
		/*CanIfHthType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
		/*CanIfCanControllerIdRef =*/ vCanIf_Channel0,
		/*CanIfHthIdSymRef =*/ CAN_CTRL_0_vCanHth,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_HrhConfigType CanIfHrhConfigData_vCanIf_Channel0[]=
{
	{
		/*CanIfHrhType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
		/*CanIfSoftwareFilterHrh =*/ FALSE,
		/*CanIfCanControllerIdRef =*/ vCanIf_Channel0,
		/*CanIfHrhIdSymRef =*/ CAN_CTRL_0_vCanHrh,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_HthConfigType CanIfHthConfigData_vCanIf_Channel1[]=
{
	{
		/*CanIfHthType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
		/*CanIfCanControllerIdRef =*/ vCanIf_Channel1,
		/*CanIfHthIdSymRef =*/ CAN_CTRL_1_vCanHth,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_HrhConfigType CanIfHrhConfigData_vCanIf_Channel1[]=
{
	{
		/*CanIfHrhType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
		/*CanIfSoftwareFilterHrh =*/ FALSE,
		/*CanIfCanControllerIdRef =*/ vCanIf_Channel1,
		/*CanIfHrhIdSymRef =*/ CAN_CTRL_1_vCanHrh,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_HthConfigType CanIfHthConfigData_vCanIf_Channel4[]=
{
	{
		/*CanIfHthType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
		/*CanIfCanControllerIdRef =*/ vCanIf_Channel4,
		/*CanIfHthIdSymRef =*/ CAN_CTRL_4_vCanHth,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_HrhConfigType CanIfHrhConfigData_vCanIf_Channel4[]=
{
	{
		/*CanIfHrhType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
		/*CanIfSoftwareFilterHrh =*/ FALSE,
		/*CanIfCanControllerIdRef =*/ vCanIf_Channel4,
		/*CanIfHrhIdSymRef =*/ CAN_CTRL_4_vCanHrh,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_InitHohConfigType CanIfHohConfigData[] =
{
	{
		/*CanConfigSet =*/ &Can_ConfigSetData,
		/*CanIfHrhConfig =*/ CanIfHrhConfigData_vCanIf_Channel0,
		/*CanIfHthConfig =*/ CanIfHthConfigData_vCanIf_Channel0,
		/*CanIf_Arc_EOL =*/ FALSE
	},
	{
		/*CanConfigSet =*/ &Can_ConfigSetData,
		/*CanIfHrhConfig =*/ CanIfHrhConfigData_vCanIf_Channel1,
		/*CanIfHthConfig =*/ CanIfHthConfigData_vCanIf_Channel1,
		/*CanIf_Arc_EOL =*/ FALSE
	},
	{
		/*CanConfigSet =*/ &Can_ConfigSetData,
		/*CanIfHrhConfig =*/ CanIfHrhConfigData_vCanIf_Channel4,
		/*CanIfHthConfig =*/ CanIfHthConfigData_vCanIf_Channel4,
		/*CanIf_Arc_EOL =*/ TRUE
	},
};

const CanIf_TxPduConfigType CanIfTxPduConfigData[] = 
{
	{
		/*CanIfTxPduId =*/ vCanIf_Channel0_vCanIf_Hth0_vEcuC_Pdu0,
		/*CanIfCanTxPduIdCanId =*/ 0,
		/*CanIfCanTxPduIdDlc =*/ 5,
		/*CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadTxPduNotifyStatus =*/ FALSE, 
#endif
		/*CanIfTxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfUserTxConfirmation =*/ NULL,
		/*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_vCanIf_Channel0[0],
		/*PduIdRef =*/ NULL
	},
	{
		/*CanIfTxPduId =*/ vCanIf_Channel0_vCanIf_Hth0_vEcuC_Pdu1,
		/*CanIfCanTxPduIdCanId =*/ 1,
		/*CanIfCanTxPduIdDlc =*/ 5,
		/*CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadTxPduNotifyStatus =*/ FALSE, 
#endif
		/*CanIfTxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfUserTxConfirmation =*/ NULL,
		/*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_vCanIf_Channel0[1],
		/*PduIdRef =*/ NULL
	},
	{
		/*CanIfTxPduId =*/ vCanIf_Channel1_vCanIf_Hth0_vEcuC_Pdu1,
		/*CanIfCanTxPduIdCanId =*/ 2,
		/*CanIfCanTxPduIdDlc =*/ 5,
		/*CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadTxPduNotifyStatus =*/ FALSE, 
#endif
		/*CanIfTxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfUserTxConfirmation =*/ NULL,
		/*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_vCanIf_Channel1[0],
		/*PduIdRef =*/ NULL
	},
	{
		/*CanIfTxPduId =*/ vCanIf_Channel4_vCanIf_Hth0_vEcuC_Pdu4,
		/*CanIfCanTxPduIdCanId =*/ 4,
		/*CanIfCanTxPduIdDlc =*/ 4,
		/*CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadTxPduNotifyStatus =*/ FALSE, 
#endif
		/*CanIfTxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfUserTxConfirmation =*/ NULL,
		/*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_vCanIf_Channel4[0],
		/*PduIdRef =*/ NULL
	},
};

const CanIf_RxPduConfigType CanIfRxPduConfigData[] = 
{
	{
		/*CanIfCanRxPduId =*/ vCanIf_Channel0_vCanIf_Hrh0_vEcuC_Pdu0,
		/*CanIfCanRxPduCanId =*/ 0,
		/*CanIfCanRxPduDlc =*/ 5,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )
		/*CanIfReadRxPduData =*/ TRUE,
#endif
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadRxPduNotifyStatus =*/ TRUE, 
#endif
		/*CanIfRxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfRxUserType =*/ CANIF_USER_TYPE_CAN_SPECIAL,
		/*CanIfUserRxIndication =*/ CanIf_UserRxIndication,
		/*CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_vCanIf_Channel0[0],
		/*PduIdRef =*/ NULL,
		/*CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,
		/*CanIfCanRxPduCanIdMask =*/ 0x7FF
	},
	{
		/*CanIfCanRxPduId =*/ vCanIf_Channel1_vCanIf_Hrh0_vEcuC_Pdu1,
		/*CanIfCanRxPduCanId =*/ 0,
		/*CanIfCanRxPduDlc =*/ 5,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )
		/*CanIfReadRxPduData =*/ TRUE,
#endif
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadRxPduNotifyStatus =*/ TRUE, 
#endif
		/*CanIfRxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfRxUserType =*/ CANIF_USER_TYPE_CAN_SPECIAL,
		/*CanIfUserRxIndication =*/ CanIf_UserRxIndication,
		/*CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_vCanIf_Channel1[0],
		/*PduIdRef =*/ NULL,
		/*CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,
		/*CanIfCanRxPduCanIdMask =*/ 0x7FF
	},
	{
		/*CanIfCanRxPduId =*/ vCanIf_Channel4_vCanIf_Hrh0_vEcuC_Pdu4,
		/*CanIfCanRxPduCanId =*/ 0,
		/*CanIfCanRxPduDlc =*/ 4,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )
		/*CanIfReadRxPduData =*/ TRUE,
#endif
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
		/*CanIfReadRxPduNotifyStatus =*/ TRUE, 
#endif
		/*CanIfRxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
		/*CanIfRxUserType =*/ CANIF_USER_TYPE_CAN_SPECIAL,
		/*CanIfUserRxIndication =*/ CanIf_UserRxIndication,
		/*CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_vCanIf_Channel4[0],
		/*PduIdRef =*/ NULL,
		/*CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,
		/*CanIfCanRxPduCanIdMask =*/ 0x7FF
	},
};

// This container contains the init parameters of the CAN
// Multiplicity 1/*/**
const CanIf_InitConfigType CanIfInitConfig =
{
	/*CanIfConfigSet =*/ 0, // Not used 
	/*CanIfNumberOfCanRxPduIds =*/ 3,
	/*CanIfNumberOfCanTXPduIds =*/ 4,
	/*CanIfNumberOfDynamicCanTXPduIds =*/ 0, // Not used
	// Containers
	/*CanIfHohConfigPtr =*/ CanIfHohConfigData,
	/*CanIfRxPduConfigPtr =*/ CanIfRxPduConfigData,
	/*CanIfTxPduConfigPtr =*/ CanIfTxPduConfigData,
};
// This container includes all necessary configuration sub-containers
// according the CAN Interface configuration structure
CanIf_ConfigType CanIf_Config =
{
	/*ControllerConfig =*/ CanIfControllerConfig,
	/*DispatchConfig =*/ &CanIfDispatchConfig,
	/*InitConfig =*/ &CanIfInitConfig,
	/*TransceiverConfig =*/ NULL, // Not used
	/*Arc_ChannelToControllerMap =*/ CanIf_Arc_ChannelToControllerMap,
	/*Arc_ChannelDefaultConfIndex =*/ CanIf_Arc_ChannelDefaultConfIndex,
};
