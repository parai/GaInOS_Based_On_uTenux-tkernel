/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#ifndef _OSEK_OS_H_
#define _OSEK_OS_H_
/* Std include of tkernel */
#include "Std_Types.h"
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
#define E_OS_ACCESS     E_OACV
#define E_OS_CALLEVEL   E_CTX
#define E_OS_ID         E_ID
#define E_OS_LIMIT      E_LIMIT
#define E_OS_NOFUNC     E_NOEXS
#define E_OS_VALUE      E_PAR
#define E_OS_RESOURCE   (-101)
#define E_OS_STATE      (-102)
/* #define E_NOT_OK        (-103) */

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
/* NOTE:
 * Problem will happened for 16 bits cpu because its longlong is 32 bits,so after
 * <(1<<32)ms/1000s/60min/60h/24day=>49.708 days, an overflow will happened.
 * but as seldom can a car run 49 days without a stop.so I choose to ignore this problem.
 * Without implement struct{long hi;unsigned long lo;} longlong for 16 bits cpu.
 */
typedef long long TickType; /* same with knl_current_time.no support of struct longlong */
/* This data type points to the data type TickType. */
typedef TickType* TickRefType;
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
/* #############################  COUNTER  ############################## */
extern TickType	knl_current_time;
StatusType GetCounterValue(CounterType CounterID,TickRefType pxValue);
StatusType GetElapsedCounterValue(CounterType CounterID,
                                  TickRefType Value,TickRefType ElapsedValue);
StatusType IncrementCounter(CounterType CounterID);
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
	(VP)NULL,    						\
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

