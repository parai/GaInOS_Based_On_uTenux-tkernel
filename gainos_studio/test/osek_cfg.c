#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vSchedulerResource */
};

/* Generate Task Stack */
GenTaskStack(vTaskInit,512);
GenTaskStack(vTaskCanTpMainFunction,512);
GenTaskStack(vTaskSender,512);
GenTaskStack(vTaskReceiver,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTaskInit,2,NULL),
	GenTaskCreInfo(vTaskCanTpMainFunction,4,NULL),
	GenTaskCreInfo(vTaskSender,5,NULL),
	GenTaskCreInfo(vTaskReceiver,5,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTaskInit */
	FALSE,	/* vTaskCanTpMainFunction */
	FALSE,	/* vTaskSender */
	FALSE,	/* vTaskReceiver */
};

TASK(vTaskInit)
{
	tm_putstring((UB*)"vTaskInit is running.\r\n");
	(void)TerminateTask();
}

TASK(vTaskCanTpMainFunction)
{
	tm_putstring((UB*)"vTaskCanTpMainFunction is running.\r\n");
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
	AlarmCallBackEntry(vAlarmCanTp),
};
ALARMCALLBACK(vAlarmCanTp)
{
	(void)tk_sta_tsk(ID_vTaskCanTpMainFunction,ID_vTaskCanTpMainFunction);
}

