#ifndef _OSEK_OS_H_
#define _OSEK_OS_H_
/* Std include of tkernel */
#include <basic.h>
#include <tk/tkernel.h>
#include <tm/tmonitor.h>
#include <tm/tm_printf.h>
#include "config.h"

/* Values for TaskStateType */
#define RUNNING   TTS_RUN
#define READY     TTS_RDY
#define WAITING   TTS_WAI
#define SUSPENDED TTS_DMT

/* Values for StatusType */
/* #define E_OK            (0u) */
#define E_OS_ACCESS     E_NOEXS
#define E_OS_CALLEVEL   E_CTX
#define E_OS_ID         E_ID
#define E_OS_LIMIT      E_LIMIT
#define E_OS_NOFUNC     E_NOSPT
#define E_OS_VALUE      E_PAR
#define E_OS_RESOURCE   (-101)
#define E_OS_STATE      (-102)
#define E_NOT_OK        (-103)

#define ALARM_NOT_IN_USE   (ID)(-1)
#define ALARM_CYC     (UB)0  /* use tkernel cyclic handler*/
#define ALARM_ALM     (UB)1  /* use tkernel alarm  handler*/
/* ============================================================================== */
/*                         Standard Type Define of OSEK                           */
/* ============================================================================== */
/* This data type identifies a task. */
typedef UINT TaskType;
/* This data type points to a variable of TaskType. */
typedef TaskType* TaskRefType;
/* This data type identifies the state of a task. */
typedef UB   TaskStateType; /* TSTAT */
/* This data type points to a variable of the data type TaskStateType. */
typedef TaskStateType* TaskStateRefType;
/* This data type represents count values in ticks. */
typedef RELTIM TickType; /* LSYSTIM/CFN_TIMER_PERIOD */
/* This data type points to the data type TickType. */
typedef SYSTIM* TickRefType;
/* This data type represents a structure for storage of counter characteristics.
 * The individual elements of the structure are: */
typedef struct
{
    /* Maximum possible allowed count value in ticks */
    TickType xMaxAllowedValue;
    /*  Number of ticks required to reach a counter-specific (significant) unit. */
    TickType xTicksPerBase;
    /* Smallest allowed value for the cycle-parameter of */
    /* SetRelAlarm/SetAbsAlarm) (only for systems with extended status). */
    TickType xMinCycle;
}AlarmBaseType;
/* This data type points to the data type AlarmBaseType. */
typedef AlarmBaseType * AlarmBaseRefType;
/* This data type represents an alarm object. */
typedef UINT AlarmType;
/* This data type represents an Counter object. */
typedef ID CounterType;
/* Data type of the event mask. */
typedef UINT EventMaskType;
/* Reference to an event mask. */
typedef EventMaskType* EventMaskRefType;
typedef UINT ResourceType;
typedef ER StatusType;
typedef UB AppModeType;
/* This data type represents the identification of system services. */
typedef UB OSServiceIdType;

/* #############################  TASK  ############################## */
#define DeclareTask(TaskName)  TaskType TaskName
#define TASK(TaskName) void TaskMain##TaskName(INT stacd,VP exinf)
#define GenTaskStack(TaskName,stksz)  static VP TaskStack##TaskName[stksz/sizeof(VP)]
#define GenTaskCreInfo(TaskName,Priority,flgid)         \
    {                                                   \
        (VP)flgid,                                      \
            TA_HLNG|TA_RNG0|TA_USERBUF,                 \
            &TaskMain##TaskName,                        \
            Priority,                                   \
            sizeof(TaskStack##TaskName),                \
            {'T','A','S','K','\0'},                     \
            TaskStack##TaskName                         \
                }
StatusType ActivateTask ( TaskType xTaskID );
StatusType TerminateTask( void );
StatusType ChainTask    ( TaskType xTaskID );
StatusType Schedule     ( void );
StatusType GetTaskID    ( TaskRefType pxTaskType );
StatusType GetTaskState ( TaskType xTaskID,TaskStateRefType pxState );
/* osek extended API */
StatusType SleepTask(TMO tmout);
StatusType WakeUpTask(ID xTask);
StatusType DelayTask(RELTIM dlytim);
/* #############################  ALARM  ############################## */
#define ALARMCALLBACK(AlarmCallbackRoutineName) \
    void AlarmCbk##AlarmCallbackRoutineName(void)
#define AlarmCallBackEntry(AlarmCallbackRoutineName) \
    &AlarmCbk##AlarmCallbackRoutineName
StatusType GetAlarmBase( AlarmType xAlarmID, AlarmBaseRefType pxInfo );
StatusType GetAlarm ( AlarmType xAlarmID ,/* (SYSTIM*) */ TickRefType pxTick );
StatusType SetRelAlarm ( AlarmType xAlarmID , TickType xIncrement ,TickType xCycle );
#if 0
StatusType SetAbsAlarm ( AlarmType xAlarmID , TickType xStart ,TickType xCycle );
#else
#define SetAbsAlarm(xAlarmID,xStart,xCycle) SetRelAlarm(xAlarmID,xStart,xCycle)
#endif
StatusType CancelAlarm ( AlarmType xAlarmID );

/* #############################  EVENT  ############################## */
StatusType SetEvent  ( TaskType xTaskID , EventMaskType pxMask );
StatusType ClearEvent( EventMaskType xMask );
StatusType GetEvent  ( TaskType xTaskID , EventMaskRefType pxEvent );
StatusType WaitEvent ( EventMaskType xMask );

/* #############################  RESOURCE  ############################## */
#define GenResourceCreInfo(cerlpri)		\
{										\
	NULL,								\
	TA_TPRI|TA_CEILING,					\
	(MIN_PRI+cerlpri),					\
	{'R','E','S','\0'}					\
}
StatusType GetResource (ResourceType xResID);
StatusType ReleaseResource ( ResourceType xResID );

/* #############################  INTERRUPT  ############################## */
void DisableAllInterrupts( void );
void EnableAllInterrupts ( void );
void SuspendAllInterrupts( void );
void ResumeAllInterrupts ( void );
void SuspendOSInterrupts( void );
void ResumeOSInterrupts ( void );


void StartOS ( AppModeType xMode );
void ShutdownOS( StatusType xError );


void ShutdownHook ( StatusType xError);
void StartupHook(void);
void ErrorHook(StatusType xError);
void PreTaskHook(void);

#include "utk_config.h"
#include "osek_cfg.h"
#include "osek_check.h"
#endif /* _OSEK_OS_H_ */

