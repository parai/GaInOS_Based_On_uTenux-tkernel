#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vRes0 */
};

/* Generate Task Stack */
GenTaskStack(vTask0,512);
GenTaskStack(vTask1,512);
GenTaskStack(vTask2,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTask0,1,NULL),
	GenTaskCreInfo(vTask1,2,ID_vTask1Event),
	GenTaskCreInfo(vTask2,3,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTask0 */
	TRUE,	/* vTask1 */
	TRUE,	/* vTask2 */
};
#include "Can.h"
TASK(vTask0)
{
    Can_PduType pdu;

    static char* sduData1 = "Hello"; /* 5 */
    static char* sduData2 = "World"; /* 5 */
    
    pdu.id=125;
    pdu.length=5;
    pdu.swPduHandle=1234;
	tm_putstring((UB*)"vTask0 is running.\r\n");
	Can_Init(&Can_ConfigData);
	Can_SetControllerMode(CAN_CTRL_1,CAN_T_START);
	for(;;)
	{
	    pdu.sdu= sduData1;
	    while(CAN_BUSY == Can_Write(CAN0_HTH,&pdu));
	    pdu.sdu= sduData2;
	    while(CAN_BUSY == Can_Write(CAN0_HTH,&pdu)); 
	    DelayTask(3000); 
	}
	(void)TerminateTask();
}

TASK(vTask1)
{
	tm_putstring((UB*)"vTask1 is running.\r\n");
	(void)TerminateTask();
}

TASK(vTask2)
{
	tm_putstring((UB*)"vTask2 is running.\r\n");
	(void)TerminateTask();
}

ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM]=
{
	AlarmCallBackEntry(vAlarm0),
	AlarmCallBackEntry(vAlarm1),
};
ALARMCALLBACK(vAlarm0)
{
	(void)tk_sta_tsk(ID_vTask1,ID_vTask1);
}

ALARMCALLBACK(vAlarm1)
{
	(void)SetEvent(ID_vTask1,vTask1Event0);
}

