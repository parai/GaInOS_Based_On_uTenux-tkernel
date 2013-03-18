#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(7),	/* vRes0 */
	GenResourceCreInfo(8),	/* vRes1 */
	GenResourceCreInfo(4),	/* vResSerial */
};

/* Generate Task Stack */
GenTaskStack(vTask0,1024);
GenTaskStack(vTask1,1024);
GenTaskStack(vTask2,1024);
GenTaskStack(vTask3,1024);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTask0,1,NULL),
	GenTaskCreInfo(vTask1,2,ID_vTask1Event),
	GenTaskCreInfo(vTask2,3,ID_vTask2Event),
	GenTaskCreInfo(vTask3,4,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTask0 */
	TRUE,	/* vTask1 */
	TRUE,	/* vTask2 */
	TRUE,	/* vTask3 */
};
TASK(vTask0)
{
	(void)tm_putstring((UB*)"vTask0 is running.\r\n");
//	(void)tm_printf((UB*)"stacd = %d,exinf = %d.\r\n",stacd,(int)exinf);
	(void)ActivateTask(ID_vTask2);
	(void)TerminateTask();
}

TASK(vTask1)
{
	(void)tm_putstring((UB*)"vTask1 is running.\r\n");
//	(void)tm_printf((UB*)"stacd = %d,exinf = %d.\r\n",(int)stacd,(int)exinf);
	(void)tm_putstring((UB*)"SetRelAlarm().\r\n");
	(void)SetRelAlarm(ID_vAlarm0, 500,3000);
	(void)SetRelAlarm(ID_vAlarm1,1000,3000);
	(void)SetRelAlarm(ID_vAlarm2,1500,3000);
	(void)TerminateTask();
}
TASK(vTask2)
{   
	(void)tm_putstring((UB*)"vTask2 is running.\r\n");
//	(void)tm_printf((UB*)"stacd = %d,exinf = %d.\r\n",stacd,(int)exinf);
	(void)WaitEvent(vTask2Event0);
	(void)ClearEvent(vTask2Event0);
	(void)TerminateTask();
}

TASK(vTask3)
{
	(void)tm_putstring((UB*)"vTask3 is running.\r\n");
//	(void)tm_printf((UB*)"stacd = %d,exinf = %d.\r\n",stacd,(int)exinf);
//	(void)SetEvent(ID_vTask2,vTask2Event0);
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
	(void)tm_putstring((UB*)"vAlarm0 cbk is running.\r\n");
}

ALARMCALLBACK(vAlarm1)
{
//	(void)tm_putstring((UB*)"vAlarm1 cbk is running.\r\n");
	(void)tk_sta_tsk(ID_vTask0,ID_vTask0);
}

ALARMCALLBACK(vAlarm2)
{
//	(void)tm_putstring((UB*)"vAlarm2 cbk is running.\r\n");
//  (void)tk_sta_tsk(ID_vTask3,ID_vTask3);
	(void)SetEvent(ID_vTask2,vTask2Event0);
}

