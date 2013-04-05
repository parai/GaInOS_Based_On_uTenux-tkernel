#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vRes0 */
};

/* Generate Task Stack */
GenTaskStack(vTask0,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTask0,1,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTask0 */
};

TASK(vTask0)
{
	tm_putstring((UB*)"vTask0 is running.\r\n");
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

