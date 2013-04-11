#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
#include "osek_os.h"

/* #####################  TASK  ########################## */
#define cfgOSEK_TASK_NUM 4
extern const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM];
extern const BOOL   OsekTaskAuotStartable[cfgOSEK_TASK_NUM];
#define ID_vTaskInit		 (MIN_TSKID+0)
#define ID_vTaskCanTpMainFunction		 (MIN_TSKID+1)
#define ID_vTaskSender		 (MIN_TSKID+2)
#define ID_vTaskReceiver		 (MIN_TSKID+3)
extern TASK(vTaskInit);
extern TASK(vTaskCanTpMainFunction);
extern TASK(vTaskSender);
extern TASK(vTaskReceiver);
/* #####################  EVENT ########################## */
#define cfgOSEK_EVENTFLAG_NUM 0
/* #####################  ALARM ########################## */
#define cfgOSEK_ALARM_NUM 1
extern ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
extern UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
extern const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM];
#define ID_vAlarmCanTp		(0)
extern ALARMCALLBACK(vAlarmCanTp);
/*  ####################  RESOURCE ####################### */
#define cfgOSEK_RESOURCE_NUM 1
extern const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM];
#define ID_vSchedulerResource		 (MIN_MTXID+0)
#endif /* _OSEK_CFG_H_ */

