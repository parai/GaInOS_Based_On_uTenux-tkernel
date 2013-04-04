
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


// Imported structs from Can_Lcfg.c
IMPORT const Can_ControllerConfigType Can_ControllerCfgData[];
IMPORT const Can_ConfigSetType Can_ConfigSetData;




// Contains the mapping from CanIf-specific Channels to Can Controllers
const Can_ControllerIdType CanIf_Arc_ChannelToControllerMap[CANIF_CHANNEL_CNT] = {
	CAN_CTRL_0, // CAN_CHL0
	CAN_CTRL_1, // CAN_CHL1
};

const uint8 CanIf_Arc_ChannelDefaultConfIndex[CANIF_CHANNEL_CNT] = {
	CANIF_CAN_CHL0_CONFIG_0,
	CANIF_CAN_CHL1_CONFIG_0,
};

// Container that gets slamed into CanIf_InitController()
// Inits ALL controllers
// Multiplicity 1/*/**
const CanIf_ControllerConfigType CanIfControllerConfig[] = {
	// This is the ConfigurationIndex in CanIf_InitController()
	
	
	{ 
		/*WakeupSupport =*/ CANIF_WAKEUP_SUPPORT_NO_WAKEUP,
		/*CanIfControllerIdRef =*/ CANIF_CAN_CHL0,
		/*CanIfDriverNameRef =*/ "FLEXCAN",  // Not used
		/*CanIfInitControllerRef =*/ &Can_ControllerCfgData[0],
	},
	
	
	{ 
		/*WakeupSupport =*/ CANIF_WAKEUP_SUPPORT_NO_WAKEUP,
		/*CanIfControllerIdRef =*/ CANIF_CAN_CHL1,
		/*CanIfDriverNameRef =*/ "FLEXCAN",  // Not used
		/*CanIfInitControllerRef =*/ &Can_ControllerCfgData[1],
	},
	
};

// Function callbacks for higher layers
const CanIf_DispatchConfigType CanIfDispatchConfig =
{
  /*CanIfBusOffNotification =*/ NULL,
  /*CanIfWakeUpNotification =*/ NULL,        // Not used
  /*CanIfWakeupValidNotification =*/ NULL,   // Not used
  /*CanIfErrorNotificaton =*/ NULL,
};


// Data for init configuration CanIfInitConfiguration

		

const CanIf_HthConfigType CanIfHthConfigData_CANIF0[] =
{
		
  { 
    /*CanIfHthType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
    /*CanIfCanControllerIdRef =*/ CANIF_CAN_CHL0,
    /*CanIfHthIdSymRef =*/ CAN_CTRL_0_vCanHohTx,
    /*CanIf_Arc_EOL =*/ TRUE,
  },
};

const CanIf_HrhConfigType CanIfHrhConfigData_CANIF0[] =
{		
  {
    /*CanIfHrhType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
    /*CanIfSoftwareFilterHrh =*/ TRUE,
    /*CanIfCanControllerHrhIdRef =*/ CANIF_CAN_CHL0,
    /*CanIfHrhIdSymRef =*/ CAN_CTRL_0_vCanHohRx,
    /*CanIf_Arc_EOL =*/ TRUE,
  },
};
		

const CanIf_HthConfigType CanIfHthConfigData_CANIF1[] =
{
		
  { 
    /*CanIfHthType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
    /*CanIfCanControllerIdRef =*/ CANIF_CAN_CHL1,
    /*CanIfHthIdSymRef =*/ CAN_CTRL_1_vCanHohTx,
    /*CanIf_Arc_EOL =*/ TRUE,
  },
};

const CanIf_HrhConfigType CanIfHrhConfigData_CANIF1[] =
{		
  {
    /*CanIfHrhType =*/ CAN_ARC_HANDLE_TYPE_BASIC,
    /*CanIfSoftwareFilterHrh =*/ TRUE,
    /*CanIfCanControllerHrhIdRef =*/ CANIF_CAN_CHL1,
    /*CanIfHrhIdSymRef =*/ CAN_CTRL_1_vCanHohRx,
    /*CanIf_Arc_EOL =*/ TRUE,
  },
};


const CanIf_InitHohConfigType CanIfHohConfigData[] = { 
		
	{
		/*CanConfigSet =*/ &Can_ConfigSetData,
		/*CanIfHrhConfig =*/ CanIfHrhConfigData_CANIF0,
	    /*CanIfHthConfig =*/ CanIfHthConfigData_CANIF0,
    	/*CanIf_Arc_EOL =*/ FALSE,
	},
		
	{
		/*CanConfigSet =*/ &Can_ConfigSetData,
		/*CanIfHrhConfig =*/ CanIfHrhConfigData_CANIF1,
	    /*CanIfHthConfig =*/ CanIfHthConfigData_CANIF1,
    	/*CanIf_Arc_EOL =*/ TRUE,
	},
};
	  
const CanIf_TxPduConfigType CanIfTxPduConfigData[] = {	
  {
    /*CanIfTxPduId =*/ CANIF_TX_PDU_ID_PDU_CAN0,
    /*CanIfCanTxPduIdCanId =*/ 0,
    /*CanIfCanTxPduIdDlc =*/ 8,
    /*CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    /*CanIfReadTxPduNotifyStatus =*/ FALSE, 
#endif
    /*CanIfTxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
    /*CanIfUserTxConfirmation =*/ NULL,
    /*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_CANIF0[0],
    /*PduIdRef =*/ NULL,
  },	
  {
    /*CanIfTxPduId =*/ CANIF_TX_PDU_ID_PDU_CAN1,
    /*CanIfCanTxPduIdCanId =*/ 0,
    /*CanIfCanTxPduIdDlc =*/ 8,
    /*CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    /*CanIfReadTxPduNotifyStatus =*/ TRUE, 
#endif
    /*CanIfTxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
    /*CanIfUserTxConfirmation =*/ NULL,
    /*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_CANIF1[0],
    /*PduIdRef =*/ NULL,
  },  
};

const CanIf_RxPduConfigType CanIfRxPduConfigData[] = {		
  {
    /*CanIfCanRxPduId =*/ CANIF_RX_PDU_ID_PDU_CAN0,
    /*CanIfCanRxPduCanId =*/ 0,
    /*CanIfCanRxPduDlc =*/ 2,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )    
    /*CanIfReadRxPduData =*/ TRUE,
#endif    
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    /*CanIfReadRxPduNotifyStatus =*/ TRUE, 
#endif
    /*CanIfRxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
	/*CanIfRxUserType =*/ CANIF_USER_TYPE_CAN_PDUR,
    /*CanIfUserRxIndication =*/ NULL,
    /*CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_CANIF0[0],
    /*PduIdRef =*/ NULL,
    /*CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,
    /*CanIfCanRxPduCanIdMask =*/ 0xFFF,
  },		
  {
    /*CanIfCanRxPduId =*/ CANIF_RX_PDU_ID_PDU_CAN1,
    /*CanIfCanRxPduCanId =*/ 0,
    /*CanIfCanRxPduDlc =*/ 2,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )    
    /*CanIfReadRxPduData =*/ TRUE,
#endif    
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    /*CanIfReadRxPduNotifyStatus =*/ FALSE, 
#endif
    /*CanIfRxPduIdCanIdType =*/ CANIF_CAN_ID_TYPE_11,
	/*CanIfRxUserType =*/ CANIF_USER_TYPE_CAN_PDUR,
    /*CanIfUserRxIndication =*/ NULL,
    /*CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_CANIF1[0],  
    /*PduIdRef =*/ NULL,
    /*CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,
    /*CanIfCanRxPduCanIdMask =*/ 0xFFF,
  },  
};

// This container contains the init parameters of the CAN
// Multiplicity 1/*/**
const CanIf_InitConfigType CanIfInitConfig =
{
  /*CanIfConfigSet =*/ 0, // Not used  
  /*CanIfNumberOfCanRxPduIds =*/ 2,
  /*CanIfNumberOfCanTXPduIds =*/ 2,
  /*CanIfNumberOfDynamicCanTXPduIds =*/ 0, // Not used

  // Containers
  /*CanIfHohConfigPtr =*/ CanIfHohConfigData,
  /*CanIfRxPduConfigPtr =*/ CanIfRxPduConfigData,
  /*CanIfTxPduConfigPtr =*/ CanIfTxPduConfigData,
};

	// This container includes all necessary configuration sub-containers
// according the CAN Interface configuration structure/*
CanIf_ConfigType CanIf_Config =
{
  /*ControllerConfig =*/ CanIfControllerConfig,
  /*DispatchConfig =*/ &CanIfDispatchConfig,
  /*InitConfig =*/ &CanIfInitConfig,
  /*TransceiverConfig =*/ NULL, // Not used
  /*Arc_ChannelToControllerMap =*/ CanIf_Arc_ChannelToControllerMap,  
  /*Arc_ChannelDefaultConfIndex =*/ CanIf_Arc_ChannelDefaultConfIndex,
};

