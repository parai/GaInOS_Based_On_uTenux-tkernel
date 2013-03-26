#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(7),	/* vRes0 */
	GenResourceCreInfo(8),	/* vRes1 */
	GenResourceCreInfo(4),	/* vResSerial */
};

/* Generate Task Stack */
GenTaskStack(vTask0,512);
GenTaskStack(vTask1,512);
GenTaskStack(vTask2,512);
GenTaskStack(vTask3,512);
GenTaskStack(vTask4,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTask0,1,NULL),
	GenTaskCreInfo(vTask1,2,ID_vTask1Event),
	GenTaskCreInfo(vTask2,3,ID_vTask2Event),
	GenTaskCreInfo(vTask3,4,NULL),
	GenTaskCreInfo(vTask4,5,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTask0 */
	TRUE,	/* vTask1 */
	TRUE,	/* vTask2 */
	TRUE,	/* vTask3 */
	TRUE,	/* vTask4 */
};

TASK(vTask0)
{
	tm_putstring((UB*)"vTask0 is running.\r\n");
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

TASK(vTask3)
{
	tm_putstring((UB*)"vTask3 is running.\r\n");
	(void)TerminateTask();
}

TASK(vTask4)
{
	tm_putstring((UB*)"vTask4 is running.\r\n");
	(void)TerminateTask();
}

ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM]=
{
	AlarmCallBackEntry(vAlarm0),
	AlarmCallBackEntry(vAlarm1),
	AlarmCallBackEntry(vAlarm2),
};
ALARMCALLBACK(vAlarm0)
{
	tm_putstring((UB*)"vAlarm0 cbk is running.\r\n");
}

ALARMCALLBACK(vAlarm1)
{
	(void)tk_sta_tsk(ID_vTask0,ID_vTask0);
}

ALARMCALLBACK(vAlarm2)
{
	(void)SetEvent(ID_vTask2,vTask2Event0);
}

