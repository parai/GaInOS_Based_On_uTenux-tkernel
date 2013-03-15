#include "osek_os.h"
#include "kernel.h"
#include "task.h"
#include "eventflag.h"
/* |------------------+----------------------------------------------------------| */
/* | Syntax:          | StatusType SetEvent ( TaskType <TaskID>                  | */
/* |                  | EventMaskType <Mask> )                                   | */
/* |------------------+----------------------------------------------------------| */
/* | Parameter (In):  | TaskID:Reference to the task for which one or several    | */
/* |                  | events are to be set.                                    | */
/* |                  | Mask:Mask of the events to be set                        | */
/* |------------------+----------------------------------------------------------| */
/* | Parameter (Out): | none                                                     | */
/* |------------------+----------------------------------------------------------| */
/* | Description:     | 1.The service may be called from an interrupt service    | */
/* |                  | routine and from the task level, but not from hook       | */
/* |                  | routines.                                                | */
/* |                  | 2.The events of task <TaskID> are set according to the   | */
/* |                  | event mask <Mask>. Calling SetEvent causes the task      | */
/* |                  | <TaskID> to be transferred to the ready state, if it     | */
/* |                  | was waiting for at least one of the events specified     | */
/* |                  | in <Mask>.                                               | */
/* |------------------+----------------------------------------------------------| */
/* | Particularities: | Any events not set in the event mask remain unchanged.   | */
/* |------------------+----------------------------------------------------------| */
/* | Status:          | Standard: 1.No error, E_OK                               | */
/* |                  | Extended: 2.Task <TaskID> is invalid, E_OS_ID            | */
/* |                  | 3.Referenced task is no extended task, E_OS_ACCESS       | */
/* |                  | 4.Events can not be set as the referenced task is in the | */
/* |                  | suspended state, E_OS_STATE                              | */
/* |------------------+----------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                               | */
/* |------------------+----------------------------------------------------------| */
StatusType SetEvent ( TaskType xTaskID , EventMaskType xMask )
{
	StatusType ercd = E_OK;
	TCB* tcb=get_tcb(xTaskID);
	ID flgid=(ID)(tcb->exinf);
	if((xTaskID >= cfgOSEK_TASK_NUM+MIN_TSKID) ||
	   (xTaskID < MIN_TSKID))
	{
		ercd = E_OS_ID;
		goto Error_Exit;
	}
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	ercd = tk_set_flg(flgid,xMask);
  Error_Exit:
	return ercd;
}

/* |------------------+---------------------------------------------------------| */
/* | Syntax:          | StatusType ClearEvent ( EventMaskType <Mask> )          | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (In)   | Mask:Mask of the events to be cleared                   | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (Out)  | none                                                    | */
/* |------------------+---------------------------------------------------------| */
/* | Description:     | The events of the extended task calling ClearEvent are  | */
/* |                  | cleared according to the event mask <Mask>.             | */
/* |------------------+---------------------------------------------------------| */
/* | Particularities: | The system service ClearEvent is restricted to extended | */
/* |                  | tasks which own the event.                              | */
/* |------------------+---------------------------------------------------------| */
/* | Status:          | Standard: 1.No error, E_OK                              | */
/* |                  | Extended: 1.Call not from extended task, E_OS_ACCESS    | */
/* |                  | 2.Call at interrupt level, E_OS_CALLEVEL                | */
/* |------------------+---------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                              | */
/* |------------------+---------------------------------------------------------| */
StatusType ClearEvent ( EventMaskType xMask )
{
	StatusType ercd = E_OK;
	ID flgid=(ID)(knl_ctxtsk->exinf);
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	ercd = tk_clr_flg(flgid,~xMask);
  Error_Exit:
	return ercd;
}

/* |------------------+--------------------------------------------------------------| */
/* | Syntax:          | StatusType GetEvent ( TaskType <TaskID>                      | */
/* |                  | EventMaskRefType <Event> )                                   | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (In):  | TaskID:Task whose event mask is to be returned.              | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (Out): | Event:Reference to the memory of the return data.            | */
/* |------------------+--------------------------------------------------------------| */
/* | Description:     | 1.This service returns the current state of all event bits   | */
/* |                  | of the task <TaskID>, not the events that the task is        | */
/* |                  | waiting for.                                                 | */
/* |                  | 2.The service may be called from interrupt service routines, | */
/* |                  | task level and some hook routines (see Figure 12-1).         | */
/* |                  | 3.The current status of the event mask of task <TaskID> is   | */
/* |                  | copied to <Event>.                                           | */
/* |------------------+--------------------------------------------------------------| */
/* | Particularities: | The referenced task shall be an extended task.               | */
/* |------------------+--------------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                                     | */
/* |                  | Extended: Task <TaskID> is invalid, E_OS_ID                  | */
/* |                  | Referenced task <TaskID> is not an extended task,            | */
/* |                  | E_OS_ACCESS                                                  | */
/* |                  | Referenced task <TaskID> is in the suspended state,          | */
/* |                  | E_OS_STATE                                                   | */
/* |------------------+--------------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                                   | */
/* |------------------+--------------------------------------------------------------| */
StatusType GetEvent ( TaskType xTaskID , EventMaskRefType pxEvent )
{
	StatusType ercd = E_OK;
	TCB* tcb=get_tcb(xTaskID);
	ID flgid=(ID)(tcb->exinf);
	FLGCB	*flgcb;
	if((xTaskID >= cfgOSEK_TASK_NUM+MIN_TSKID) ||
	   (xTaskID < MIN_TSKID))
	{
		ercd = E_OS_ID;
		goto Error_Exit;
	}
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	flgcb = get_flgcb(flgid);
	*pxEvent = flgcb->flgptn;
  Error_Exit:
	return ercd;
}


/* |------------------+------------------------------------------------------------| */
/* | Syntax:          | StatusType WaitEvent ( EventMaskType <Mask> )              | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (In):  | Mask:Mask of the events waited for.                        | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (Out): | none                                                       | */
/* |------------------+------------------------------------------------------------| */
/* | Description:     | The state of the calling task is set to waiting, unless    | */
/* |                  | at least one of the events specified in <Mask> has         | */
/* |                  | already been set.                                          | */
/* |------------------+------------------------------------------------------------| */
/* | Particularities: | 1.This call enforces rescheduling, if the wait condition   | */
/* |                  | occurs. If rescheduling takes place, the internal resource | */
/* |                  | of the task is released while the task is in the waiting   | */
/* |                  | state.                                                     | */
/* |                  | 2.This service shall only be called from the extended task | */
/* |                  | owning the event.                                          | */
/* |------------------+------------------------------------------------------------| */
/* | Status:          | Standard:No error, E_OK                                    | */
/* |                  | Extended:Calling task is not an extended task, E_OS_ACCESS | */
/* |                  | Calling task occupies resources, E_OS_RESOURCE             | */
/* |                  | Call at interrupt level, E_OS_CALLEVEL                     | */
/* |------------------+------------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                                 | */
/* |------------------+------------------------------------------------------------| */
StatusType WaitEvent( EventMaskType xMask )
{
	UINT flgptn;
	StatusType ercd = E_OK;
	ID flgid=(ID)(knl_ctxtsk->exinf);
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	ercd = tk_wai_flg(flgid,xMask,TWF_ORW,&flgptn,TMO_FEVR);
  Error_Exit:
	return ercd;
}

