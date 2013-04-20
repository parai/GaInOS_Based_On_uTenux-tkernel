#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vResScheduler */
};

/* Generate Task Stack */
GenTaskStack(vTaskInit,512);
GenTaskStack(vTaskMainFunction,512);
GenTaskStack(vTaskSender,512);
GenTaskStack(vTaskReceiver,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTaskInit,1,NULL),
	GenTaskCreInfo(vTaskMainFunction,2,NULL),
	GenTaskCreInfo(vTaskSender,3,NULL),
	GenTaskCreInfo(vTaskReceiver,4,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTaskInit */
	FALSE,	/* vTaskMainFunction */
	FALSE,	/* vTaskSender */
	FALSE,	/* vTaskReceiver */
};

TASK(vTaskInit)
{
	tm_putstring((UB*)"vTaskInit is running.\r\n");
	(void)TerminateTask();
}

TASK(vTaskMainFunction)
{
	tm_putstring((UB*)"vTaskMainFunction is running.\r\n");
	(void)TerminateTask();
}

TASK(vTaskSender)
{
	tm_putstring((UB*)"vTaskSender is running.\r\n");
	(void)TerminateTask();
}

TASK(vTaskReceiver)
{
	tm_putstring((UB*)"vTaskReceiver is running.\r\n");
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

