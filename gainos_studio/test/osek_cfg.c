#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vRes0 */
};

/* Generate Task Stack */
GenTaskStack(vTask0,512);
GenTaskStack(vTask1,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTask0,1,ID_vTask0Event),
	GenTaskCreInfo(vTask1,2,ID_vTask1Event),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTask0 */
	TRUE,	/* vTask1 */
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

ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM]=
{
	AlarmCallBackEntry(vAlarm0),
	AlarmCallBackEntry(vAlarm1),
};
ALARMCALLBACK(vAlarm0)
{
	(void)tk_sta_tsk(ID_vTask0,ID_vTask0);
}

ALARMCALLBACK(vAlarm1)
{
	(void)tk_sta_tsk(ID_vTask1,ID_vTask1);
}

