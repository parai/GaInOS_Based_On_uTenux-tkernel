#include "Com.h"
#include "Com_Internal.h"
#include <stdlib.h>
#if defined(USE_PDUR)
#include "PduR.h"
#endif

//Signal init values.
const uint8 vCom_IPdu0_Signal0_InitValue[] ={0x01, 0x02, 0x03, };
const uint8 vCom_IPdu0_SigGrp0_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu0_SigGrp0_Signal1_InitValue = 0x00;
const uint8 vCom_IPdu1_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu1_SigGrp0_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu1_SigGrp0_Signal1_InitValue = 0x00;
const uint8 vCom_IPdu2_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu2_SigGrp0_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu2_SigGrp0_Signal1_InitValue = 0x00;
const uint8 vCom_IPdu3_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu3_SigGrp0_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu3_SigGrp0_Signal1_InitValue = 0x00;
const uint8 vCom_IPdu4_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu4_Signal1_InitValue[] ={0x00, };
const uint8 vCom_IPdu5_Signal0_InitValue = 0x00;
const uint8 vCom_IPdu5_Signal1_InitValue[] ={0x00, };

//Group signal definitions
#if(COM_N_GROUP_SIGNALS > 0)
const ComGroupSignal_type ComGroupSignal[] = {
	{
		/*ComBitPosition=*/ 0,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu0_SigGrp0_Signal0,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu0_SigGrp0_Signal0_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 8,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu0_SigGrp0_Signal1,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu0_SigGrp0_Signal1_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 0,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu1_SigGrp0_Signal0,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu1_SigGrp0_Signal0_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 8,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu1_SigGrp0_Signal1,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu1_SigGrp0_Signal1_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 0,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu2_SigGrp0_Signal0,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu2_SigGrp0_Signal0_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 8,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu2_SigGrp0_Signal1,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu2_SigGrp0_Signal1_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 0,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu3_SigGrp0_Signal0,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu3_SigGrp0_Signal0_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ FALSE
	},
	{
		/*ComBitPosition=*/ 8,
		/*ComBitSize=*/ 8,
		/*ComHandleId=*/ vCom_IPdu3_SigGrp0_Signal1,
		/*ComSignalEndianess=*/ COM_BIG_ENDIAN,
		/*ComSignalInitValue=*/ &vCom_IPdu3_SigGrp0_Signal1_InitValue,
		/*ComSignalType=*/ UINT8,
		/*Com_Arc_EOL=*/ TRUE
	},
};

/* SignalGroup GroupSignals lists. */
const ComGroupSignal_type * const vCom_IPdu0_SigGrp0_SignalRefs[] = {
	&ComGroupSignal[ vCom_IPdu0_SigGrp0_Signal0 ],
	&ComGroupSignal[ vCom_IPdu0_SigGrp0_Signal1 ],
	NULL
};
const ComGroupSignal_type * const vCom_IPdu1_SigGrp0_SignalRefs[] = {
	&ComGroupSignal[ vCom_IPdu1_SigGrp0_Signal0 ],
	&ComGroupSignal[ vCom_IPdu1_SigGrp0_Signal1 ],
	NULL
};
const ComGroupSignal_type * const vCom_IPdu2_SigGrp0_SignalRefs[] = {
	&ComGroupSignal[ vCom_IPdu2_SigGrp0_Signal0 ],
	&ComGroupSignal[ vCom_IPdu2_SigGrp0_Signal1 ],
	NULL
};
const ComGroupSignal_type * const vCom_IPdu3_SigGrp0_SignalRefs[] = {
	&ComGroupSignal[ vCom_IPdu3_SigGrp0_Signal0 ],
	&ComGroupSignal[ vCom_IPdu3_SigGrp0_Signal1 ],
	NULL
};
#endif	/* COM_N_GROUP_SIGNALS */

/* IPdu buffers and signal group buffers */
uint8 vCom_IPdu0_IPduBuffer[5];
uint8 vCom_IPdu0_SigGrp0_SignalGroupBuffer[2];
uint8 vCom_IPdu1_IPduBuffer[3];
uint8 vCom_IPdu1_IPduDeferredRxBuffer[3];
uint8 vCom_IPdu1_SigGrp0_SignalGroupBuffer[2];
uint8 vCom_IPdu2_IPduBuffer[3];
uint8 vCom_IPdu2_SigGrp0_SignalGroupBuffer[2];
uint8 vCom_IPdu3_IPduBuffer[3];
uint8 vCom_IPdu3_IPduDeferredRxBuffer[3];
uint8 vCom_IPdu3_SigGrp0_SignalGroupBuffer[2];
uint8 vCom_IPdu4_IPduBuffer[4];
uint8 vCom_IPdu4_IPduDeferredRxBuffer[4];
uint8 vCom_IPdu5_IPduBuffer[4];

//Signal definitions
const ComSignal_type ComSignal[] = {
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 24,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu0_Signal0,
		/* .ComNotification = */ vCom_IPdu0_Signal0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu0_Signal0_InitValue,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu0_Signal0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu0,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 24,
		/* .ComBitSize = */ 16,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu0_SigGrp0,
		/* .ComNotification = */ vCom_IPdu0_SigGrp0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_OPAQUE,
		/* .ComSignalInitValue = */ NULL,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu0_SigGrp0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ TRUE,
		/* .ComGroupSignal = */ vCom_IPdu0_SigGrp0_SignalRefs,
		/* .Com_Arc_ShadowBuffer = */ vCom_IPdu0_SigGrp0_SignalGroupBuffer,
		/* .ComIPduHandleId = */ vCom_IPdu0,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 8,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu1_Signal0,
		/* .ComNotification = */ vCom_IPdu1_Signal0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu1_Signal0_InitValue,
		/* .ComSignalType = */ UINT8,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu1_Signal0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu1,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 8,
		/* .ComBitSize = */ 16,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu1_SigGrp0,
		/* .ComNotification = */ vCom_IPdu1_SigGrp0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_OPAQUE,
		/* .ComSignalInitValue = */ NULL,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu1_SigGrp0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ TRUE,
		/* .ComGroupSignal = */ vCom_IPdu1_SigGrp0_SignalRefs,
		/* .Com_Arc_ShadowBuffer = */ vCom_IPdu1_SigGrp0_SignalGroupBuffer,
		/* .ComIPduHandleId = */ vCom_IPdu1,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 8,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu2_Signal0,
		/* .ComNotification = */ vCom_IPdu2_Signal0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu2_Signal0_InitValue,
		/* .ComSignalType = */ UINT8,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu2_Signal0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu2,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 8,
		/* .ComBitSize = */ 16,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu2_SigGrp0,
		/* .ComNotification = */ vCom_IPdu2_SigGrp0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_OPAQUE,
		/* .ComSignalInitValue = */ NULL,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu2_SigGrp0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ TRUE,
		/* .ComGroupSignal = */ vCom_IPdu2_SigGrp0_SignalRefs,
		/* .Com_Arc_ShadowBuffer = */ vCom_IPdu2_SigGrp0_SignalGroupBuffer,
		/* .ComIPduHandleId = */ vCom_IPdu2,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 8,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu3_Signal0,
		/* .ComNotification = */ vCom_IPdu3_Signal0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu3_Signal0_InitValue,
		/* .ComSignalType = */ UINT8,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu3_Signal0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu3,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 8,
		/* .ComBitSize = */ 16,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu3_SigGrp0,
		/* .ComNotification = */ vCom_IPdu3_SigGrp0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_OPAQUE,
		/* .ComSignalInitValue = */ NULL,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu3_SigGrp0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ TRUE,
		/* .ComGroupSignal = */ vCom_IPdu3_SigGrp0_SignalRefs,
		/* .Com_Arc_ShadowBuffer = */ vCom_IPdu3_SigGrp0_SignalGroupBuffer,
		/* .ComIPduHandleId = */ vCom_IPdu3,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 8,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu4_Signal0,
		/* .ComNotification = */ vCom_IPdu4_Signal0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu4_Signal0_InitValue,
		/* .ComSignalType = */ UINT8,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu4_Signal0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu4,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 8,
		/* .ComBitSize = */ 24,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu4_Signal1,
		/* .ComNotification = */ vCom_IPdu4_Signal1_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu4_Signal1_InitValue,
		/* .ComSignalType = */ UINT8_DYN,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu4_Signal1_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu4,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 8,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu5_Signal0,
		/* .ComNotification = */ vCom_IPdu5_Signal0_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu5_Signal0_InitValue,
		/* .ComSignalType = */ UINT8,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu5_Signal0_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu5,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 8,
		/* .ComBitSize = */ 24,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu5_Signal1,
		/* .ComNotification = */ vCom_IPdu5_Signal1_Notification,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu5_Signal1_InitValue,
		/* .ComSignalType = */ UINT8_DYN,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ vCom_IPdu5_Signal1_TimeoutNotification,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu5,
		/* .Com_Arc_EOL = */ TRUE
	},
};

//I-PDU group definitions
const ComIPduGroup_type ComIPduGroup[] = {
	{
		/* .ComIPduGroupHandleId = */ vCom_IPduGrp0,
		/* .Com_Arc_EOL = */ TRUE
	},
};

/* IPdu signal lists. */
const ComSignal_type * const vCom_IPdu0_SignalRefs[] = {
	&ComSignal[ vCom_IPdu0_Signal0 ],
	&ComSignal[ vCom_IPdu0_SigGrp0 ],
	NULL
};
const ComSignal_type * const vCom_IPdu1_SignalRefs[] = {
	&ComSignal[ vCom_IPdu1_Signal0 ],
	&ComSignal[ vCom_IPdu1_SigGrp0 ],
	NULL
};
const ComSignal_type * const vCom_IPdu2_SignalRefs[] = {
	&ComSignal[ vCom_IPdu2_Signal0 ],
	&ComSignal[ vCom_IPdu2_SigGrp0 ],
	NULL
};
const ComSignal_type * const vCom_IPdu3_SignalRefs[] = {
	&ComSignal[ vCom_IPdu3_Signal0 ],
	&ComSignal[ vCom_IPdu3_SigGrp0 ],
	NULL
};
const ComSignal_type * const vCom_IPdu4_SignalRefs[] = {
	&ComSignal[ vCom_IPdu4_Signal0 ],
	&ComSignal[ vCom_IPdu4_Signal1 ],
	NULL
};
const ComSignal_type * const vCom_IPdu5_SignalRefs[] = {
	&ComSignal[ vCom_IPdu5_Signal0 ],
	&ComSignal[ vCom_IPdu5_Signal1 ],
	NULL
};
//I-PDU definitions
const ComIPdu_type ComIPdu[] = {
	{// vCom_IPdu0
		/* .ComIPduCallout = */ vCom_IPdu0_Callout,
		/* .ArcIPduOutgoingId = */ PDUR_TX_vEcuC_Pdu0,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 5,
		/* .ComIPduDirection = */ SEND,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 0,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu0_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ NULL,
		/* .ComIPduGroupRef = */ vCom_IPdu0_SignalRefs,
		/* .ComIPduDynSignalRef = */ NULL,
		/* .Com_Arc_EOL = */ FALSE,
	},
	{// vCom_IPdu1
		/* .ComIPduCallout = */ vCom_IPdu1_Callout,
		/* .ArcIPduOutgoingId = */ PDUR_RX_vEcuC_Pdu0,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 3,
		/* .ComIPduDirection = */ RECEIVE,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 0,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu1_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ vCom_IPdu1_IPduDeferredRxBuffer,
		/* .ComIPduGroupRef = */ vCom_IPdu1_SignalRefs,
		/* .ComIPduDynSignalRef = */ NULL,
		/* .Com_Arc_EOL = */ FALSE,
	},
	{// vCom_IPdu2
		/* .ComIPduCallout = */ vCom_IPdu2_Callout,
		/* .ArcIPduOutgoingId = */ PDUR_TX_vEcuC_Pdu1,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 3,
		/* .ComIPduDirection = */ SEND,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 0,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu2_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ NULL,
		/* .ComIPduGroupRef = */ vCom_IPdu2_SignalRefs,
		/* .ComIPduDynSignalRef = */ NULL,
		/* .Com_Arc_EOL = */ FALSE,
	},
	{// vCom_IPdu3
		/* .ComIPduCallout = */ vCom_IPdu3_Callout,
		/* .ArcIPduOutgoingId = */ PDUR_RX_vEcuC_Pdu1,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 3,
		/* .ComIPduDirection = */ RECEIVE,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 0,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu3_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ vCom_IPdu3_IPduDeferredRxBuffer,
		/* .ComIPduGroupRef = */ vCom_IPdu3_SignalRefs,
		/* .ComIPduDynSignalRef = */ NULL,
		/* .Com_Arc_EOL = */ FALSE,
	},
	{// vCom_IPdu4
		/* .ComIPduCallout = */ vCom_IPdu4_Callout,
		/* .ArcIPduOutgoingId = */ PDUR_TX_vEcuC_Pdu0,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 4,
		/* .ComIPduDirection = */ RECEIVE,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 0,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu4_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ vCom_IPdu4_IPduDeferredRxBuffer,
		/* .ComIPduGroupRef = */ vCom_IPdu4_SignalRefs,
		/* .ComIPduDynSignalRef = */ &ComSignal[ vCom_IPdu4_Signal1 ],
		/* .Com_Arc_EOL = */ FALSE,
	},
	{// vCom_IPdu5
		/* .ComIPduCallout = */ vCom_IPdu5_Callout,
		/* .ArcIPduOutgoingId = */ PDUR_TX_vEcuC_Pdu4,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 4,
		/* .ComIPduDirection = */ SEND,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 0,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu5_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ NULL,
		/* .ComIPduGroupRef = */ vCom_IPdu5_SignalRefs,
		/* .ComIPduDynSignalRef = */ &ComSignal[ vCom_IPdu5_Signal1 ],
		/* .Com_Arc_EOL = */ FALSE,
	},
};

const Com_ConfigType ComConfiguration = {
/* .ComConfigurationId = */ 1,
/* .ComIPdu = */ ComIPdu,
/* .ComIPduGroup = */ ComIPduGroup,
/* .ComSignal = */ ComSignal,
/* .ComGroupSignal = */ ComGroupSignal
};

Com_Arc_IPdu_type Com_Arc_IPdu[] = {
	{ // vCom_IPdu0
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
	{ // vCom_IPdu1
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
	{ // vCom_IPdu2
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
	{ // vCom_IPdu3
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
	{ // vCom_IPdu4
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
	{ // vCom_IPdu5
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
};

Com_Arc_Signal_type Com_Arc_Signal[] = {
	{ // vCom_IPdu0_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu0_SigGrp0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu1_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu1_SigGrp0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu2_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu2_SigGrp0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu3_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu3_SigGrp0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu4_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu4_Signal1
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu5_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu5_Signal1
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
};

#if(COM_N_GROUP_SIGNALS > 0)
Com_Arc_GroupSignal_type Com_Arc_GroupSignal[COM_N_GROUP_SIGNALS];
#endif

const Com_Arc_Config_type Com_Arc_Config = {
	/* .ComIPdu = */ Com_Arc_IPdu,
	/* .ComSignal = */ Com_Arc_Signal,
#if(COM_N_GROUP_SIGNALS > 0)
	/* .ComGroupSignal = */ Com_Arc_GroupSignal
#else
    /* .ComGroupSignal = */ NULL
#endif
};

