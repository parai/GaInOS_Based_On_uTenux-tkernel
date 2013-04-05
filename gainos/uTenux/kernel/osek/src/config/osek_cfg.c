#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vRes0 */
	GenResourceCreInfo(2),	/* vRes1 */
};

/* Generate Task Stack */
GenTaskStack(vTask0,512);
GenTaskStack(vTask1,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTask0,1,NULL),
	GenTaskCreInfo(vTask1,2,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTask0 */
	TRUE,	/* vTask1 */
};

#include "Can.h"
#include "CanIf.h"
TASK(vTask0)
{
#if 1
    PduInfoType pdu;
    static char* sduData0 = "Parai"; /* 5 */
    static char* sduData1 = "Hello"; /* 5 */
    static char* sduData2 = "World"; /* 5 */
    static char* sduData3 = "Happy"; /* 5 */
    
    pdu.SduLength=5;
	tm_putstring((UB*)"vTask0 is running.\r\n");
	Can_Init(&Can_ConfigData);
	CanIf_Init(&CanIf_Config);
	CanIf_SetControllerMode(vCanIf_Channel0,CANIF_CS_STARTED);
	CanIf_SetControllerMode(vCanIf_Channel1,CANIF_CS_STARTED);
	CanIf_SetControllerMode(vCanIf_Channel4,CANIF_CS_STARTED);
	for(;;)
	{
#if 1
	    pdu.SduDataPtr= sduData0;
	    while(E_NOT_OK == CanIf_Transmit(vCanIf_Channel0_vCanIf_Hth0_vEcuC_Pdu0,&pdu));
	    pdu.SduDataPtr= sduData1;
	    while(E_NOT_OK == CanIf_Transmit(vCanIf_Channel0_vCanIf_Hth0_vEcuC_Pdu1,&pdu));
	    pdu.SduDataPtr= sduData2;
	    while(E_NOT_OK == CanIf_Transmit(vCanIf_Channel1_vCanIf_Hth0_vEcuC_Pdu1,&pdu));
	    pdu.SduDataPtr= sduData3;
	    while(E_NOT_OK == CanIf_Transmit(vCanIf_Channel4_vCanIf_Hth0_vEcuC_Pdu4,&pdu));
#endif
	    DelayTask(250); 
	}
#endif
	(void)TerminateTask();
}


TASK(vTask1)
{
	tm_putstring((UB*)"vTask1 is running.\r\n");
	(void)TerminateTask();
}

ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM]=
{
	AlarmCallBackEntry(vAlarm0),
};
ALARMCALLBACK(vAlarm0)
{
	tm_putstring((UB*)"vAlarm0 cbk is running.\r\n");
}

