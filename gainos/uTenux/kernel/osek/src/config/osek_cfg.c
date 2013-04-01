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
TASK(vTask0)
{
#if 1
    Can_PduType pdu;
    static char* sduData0 = "Parai"; /* 5 */
    static char* sduData1 = "Hello"; /* 5 */
    static char* sduData2 = "World"; /* 5 */
    
    pdu.id=125;
    pdu.length=5;
    pdu.swPduHandle=1234;
	tm_putstring((UB*)"vTask0 is running.\r\n");
	Can_Init(&Can_ConfigData);
	Can_SetControllerMode(CAN_CTRL_0,CAN_T_START);
	Can_SetControllerMode(CAN_CTRL_1,CAN_T_START);
	Can_SetControllerMode(CAN_CTRL_4,CAN_T_START);
	for(;;)
	{
	    pdu.sdu= sduData0;
	    while(CAN_BUSY == Can_Write(CAN_CTRL_0_vCanHohTx,&pdu));
	    pdu.sdu= sduData1;
	    while(CAN_BUSY == Can_Write(CAN_CTRL_0_vCanHohTx,&pdu));
	    pdu.sdu= sduData2;
	    while(CAN_BUSY == Can_Write(CAN_CTRL_0_vCanHohTx,&pdu));
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

