/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2008 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.00
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2008/02/25.
 *
 *----------------------------------------------------------------------
 */

/*
 *	utk_config_func.h
 *	System Configuration Definition
 */

#ifndef _UTK_CONFIG_FUNC_H_
#define _UTK_CONFIG_FUNC_H_

/*
 * System calls
 */
#define USE_FUNC_TK_CRE_TSK
#define USE_FUNC_TK_DEL_TSK
#define USE_FUNC_TK_STA_TSK
#define USE_FUNC_TK_EXT_TSK
#define USE_FUNC_TK_EXD_TSK
#define USE_FUNC_TK_TER_TSK
#define USE_FUNC_TK_DIS_DSP
#define USE_FUNC_TK_ENA_DSP
#define USE_FUNC_TK_CHG_PRI
#define USE_FUNC_TK_ROT_RDQ
#define USE_FUNC_TK_REL_WAI
#define USE_FUNC_TK_GET_TID
#define USE_FUNC_TK_GET_REG
#define USE_FUNC_TK_SET_REG
#define USE_FUNC_TK_REF_TSK
#define USE_FUNC_TK_SUS_TSK
#define USE_FUNC_TK_RSM_TSK
#define USE_FUNC_TK_FRSM_TSK
#define USE_FUNC_TK_SLP_TSK
#define USE_FUNC_TK_WUP_TSK
#define USE_FUNC_TK_CAN_WUP

#if CFN_MAX_SEMID > 0
#define USE_FUNC_TK_CRE_SEM
#define USE_FUNC_TK_DEL_SEM
#define USE_FUNC_TK_SIG_SEM
#define USE_FUNC_TK_WAI_SEM
#define USE_FUNC_TK_REF_SEM
#define USE_FUNC_SEMAPHORE_INITIALIZE
#define USE_FUNC_SEMCB_TABLE
#if USE_DBGSPT
#define USE_FUNC_TD_LST_SEM
#define USE_FUNC_TD_REF_SEM
#define USE_FUNC_TD_SEM_QUE
#define USE_FUNC_SEMAPHORE_GETNAME
#endif
#endif

#if CFN_MAX_MTXID > 0
#define USE_FUNC_TK_CRE_MTX
#define USE_FUNC_TK_DEL_MTX
#define USE_FUNC_TK_LOC_MTX
#define USE_FUNC_TK_UNL_MTX
#define USE_FUNC_TK_REF_MTX
#define USE_FUNC_MUTEX_INITIALIZE
#define USE_FUNC_MTXCB_TABLE
#define USE_FUNC_RELEASE_MUTEX
#define USE_FUNC_SIGNAL_ALL_MUTEX
#define USE_FUNC_CHG_PRI_MUTEX
#if USE_DBGSPT
#define USE_FUNC_TD_LST_MTX
#define USE_FUNC_TD_REF_MTX
#define USE_FUNC_TD_MTX_QUE
#define USE_FUNC_MUTEX_GETNAME
#endif
#endif

#if CFN_MAX_FLGID > 0
#define USE_FUNC_TK_CRE_FLG
#define USE_FUNC_TK_DEL_FLG
#define USE_FUNC_TK_SET_FLG
#define USE_FUNC_TK_CLR_FLG
#define USE_FUNC_TK_WAI_FLG
#define USE_FUNC_TK_REF_FLG
#define USE_FUNC_EVENTFLAG_INITIALIZE
#define USE_FUNC_FLGCB_TABLE
#if USE_DBGSPT
#define USE_FUNC_TD_LST_FLG
#define USE_FUNC_TD_REF_FLG
#define USE_FUNC_TD_FLG_QUE
#define USE_FUNC_EVENTFLAG_GETNAME
#endif
#endif

#if CFN_MAX_MBXID > 0
#define USE_FUNC_TK_CRE_MBX
#define USE_FUNC_TK_DEL_MBX
#define USE_FUNC_TK_SND_MBX
#define USE_FUNC_TK_RCV_MBX
#define USE_FUNC_TK_REF_MBX
#define USE_FUNC_MAILBOX_INITIALIZE
#define USE_FUNC_MBXCB_TABLE
#if USE_DBGSPT
#define USE_FUNC_TD_LST_MBX
#define USE_FUNC_TD_REF_MBX
#define USE_FUNC_TD_MBX_QUE
#define USE_FUNC_MAILBOX_GETNAME
#endif
#endif

#if CFN_MAX_MBFID > 0
#define USE_FUNC_TK_CRE_MBF
#define USE_FUNC_TK_DEL_MBF
#define USE_FUNC_TK_SND_MBF
#define USE_FUNC_TK_RCV_MBF
#define USE_FUNC_TK_REF_MBF
#define USE_FUNC_MESSAGEBUFFER_INITIALIZE
#define USE_FUNC_MBFCB_TABLE
#define USE_FUNC_MSG_TO_MBF
#define USE_FUNC_MBF_WAKEUP
#if USE_DBGSPT
#define USE_FUNC_TD_LST_MBF
#define USE_FUNC_TD_REF_MBF
#define USE_FUNC_TD_SMBF_QUE
#define USE_FUNC_TD_RMBF_QUE
#define USE_FUNC_MESSAGEBUFFER_GETNAME
#endif
#endif

#if CFN_MAX_PORID > 0
#define USE_FUNC_TK_CRE_POR
#define USE_FUNC_TK_DEL_POR
#define USE_FUNC_TK_CAL_POR
#define USE_FUNC_TK_ACP_POR
#define USE_FUNC_TK_FWD_POR
#define USE_FUNC_TK_RPL_RDV
#define USE_FUNC_TK_REF_POR
#define USE_FUNC_RENDEZVOUS_INITIALIZE
#define USE_FUNC_PORCB_TABLE
#define USE_FUNC_WSPEC_CAL
#define USE_FUNC_WSPEC_RDV
#if USE_DBGSPT
#define USE_FUNC_TD_LST_POR
#define USE_FUNC_TD_REF_POR
#define USE_FUNC_TD_CAL_QUE
#define USE_FUNC_TD_ACP_QUE
#define USE_FUNC_RENDEZVOUS_GETNAME
#endif
#endif

#define USE_FUNC_HLL_INTHDR
#define USE_FUNC_TK_DEF_INT
#define USE_FUNC_TK_RET_INT

#if CFN_MAX_MPLID > 0
#define USE_FUNC_TK_CRE_MPL
#define USE_FUNC_TK_DEL_MPL
#define USE_FUNC_TK_GET_MPL
#define USE_FUNC_TK_REL_MPL
#define USE_FUNC_TK_REF_MPL
#define USE_FUNC_MEMORYPOOL_INITIALIZE
#define USE_FUNC_MPLCB_TABLE
#define USE_FUNC_MPL_WAKEUP
#if USE_DBGSPT
#define USE_FUNC_TD_LST_MPL
#define USE_FUNC_TD_REF_MPL
#define USE_FUNC_TD_MPL_QUE
#define USE_FUNC_MEMORYPOOL_GETNAME
#endif
#endif

#if CFN_MAX_MPFID > 0
#define USE_FUNC_TK_CRE_MPF
#define USE_FUNC_TK_DEL_MPF
#define USE_FUNC_TK_GET_MPF
#define USE_FUNC_TK_REL_MPF
#define USE_FUNC_TK_REF_MPF
#define USE_FUNC_FIX_MEMORYPOOL_INITIALIZE
#define USE_FUNC_MPFCB_TABLE
#if USE_DBGSPT
#define USE_FUNC_TD_LST_MPF
#define USE_FUNC_TD_REF_MPF
#define USE_FUNC_TD_MPF_QUE
#define USE_FUNC_FIX_MEMORYPOOL_GETNAME
#endif
#endif

#define USE_FUNC_TK_SET_TIM
#define USE_FUNC_TK_GET_TIM
#define USE_FUNC_TK_GET_OTM
#define USE_FUNC_TK_DLY_TSK

#if CFN_MAX_CYCID > 0
#define USE_FUNC_TK_CRE_CYC
#define USE_FUNC_TK_DEL_CYC
#define USE_FUNC_TK_STA_CYC
#define USE_FUNC_TK_STP_CYC
#define USE_FUNC_TK_REF_CYC
#define USE_FUNC_CYCLICHANDLER_INITIALIZE
#define USE_FUNC_CYCCB_TABLE
#define USE_FUNC_CALL_CYCHDR
#if USE_DBGSPT
#define USE_FUNC_TD_LST_CYC
#define USE_FUNC_TD_REF_CYC
#define USE_FUNC_CYCLICHANDLER_GETNAME
#endif
#endif

#if CFN_MAX_ALMID > 0
#define USE_FUNC_TK_CRE_ALM
#define USE_FUNC_TK_DEL_ALM
#define USE_FUNC_TK_STA_ALM
#define USE_FUNC_TK_STP_ALM
#define USE_FUNC_TK_REF_ALM
#define USE_FUNC_ALARMHANDLER_INITIALIZE
#define USE_FUNC_ALMCB_TABLE
#define USE_FUNC_CALL_ALMHDR
#if USE_DBGSPT
#define USE_FUNC_TD_LST_ALM
#define USE_FUNC_TD_REF_ALM
#define USE_FUNC_ALARMHANDLER_GETNAME
#endif
#endif

#define USE_FUNC_TK_REF_VER
#define USE_FUNC_TK_REF_SYS
#define USE_FUNC_LOWPOW_DISCNT

#if USE_DBGSPT
/* Refer each object usage state */
#define USE_FUNC_TD_LST_TSK
#define USE_FUNC_TD_REF_TSK
#define USE_FUNC_TD_INF_TSK
#define USE_FUNC_TD_GET_REG
#define USE_FUNC_TD_SET_REG
#define USE_FUNC_TASK_GETNAME

/* Refer system state */
#define USE_FUNC_TD_REF_SYS
#define USE_FUNC_TD_GET_TIM
#define USE_FUNC_TD_GET_OTM

/* Refer ready queue */
#define USE_FUNC_TD_RDY_QUE

/* Execution trace */
#if USE_HOOK_TRACE
#define USE_FUNC_TD_HOK_SVC
#define USE_FUNC_TD_HOK_DSP
#define USE_FUNC_TD_HOK_INT
#define USE_FUNC_HOOK_ENTERFN
#define USE_FUNC_HOOK_EXECFN
#define USE_FUNC_HOOK_IENTERFN
#endif

/* Object name */
#define USE_FUNC_OBJECT_GETNAME
#define USE_FUNC_TD_REF_DSNAME
#define USE_FUNC_TD_SET_DSNAME

#endif /* USE_DBGSPT */

/*
 * Other functions
 */

/* tstdlib */
#define USE_FUNC_TSTDLIB_BITCLR
#define USE_FUNC_TSTDLIB_BITSET
#define USE_FUNC_TSTDLIB_BITSEARCH1


/* other functions */
#define USE_FUNC_WSPEC_SLP

/* task concerning */
#define USE_FUNC_CTXTSK
#define USE_FUNC_TCB_TABLE
#define USE_FUNC_TASK_INITIALIZE
#define USE_FUNC_MAKE_DORMANT
#define USE_FUNC_MAKE_READY
#define USE_FUNC_MAKE_NON_READY
#define USE_FUNC_CHANGE_TASK_PRIORITY
#define USE_FUNC_ROTATE_READY_QUEUE
#define USE_FUNC_ROTATE_READY_QUEUE_RUN
#define USE_FUNC_DEL_TSK
#define USE_FUNC_TER_TSK

/* wait concerning */
#define USE_FUNC_WAIT_RELEASE_OK
#define USE_FUNC_WAIT_RELEASE_OK_ERCD
#define USE_FUNC_WAIT_RELEASE_NG
#define USE_FUNC_WAIT_RELEASE_TMOUT
#define USE_FUNC_MAKE_WAIT
#define USE_FUNC_MAKE_WAIT_RELTIM
#define USE_FUNC_WAIT_DELETE
#define USE_FUNC_WAIT_TSKID
#define USE_FUNC_GCB_MAKE_WAIT
#define USE_FUNC_GCB_CHANGE_PRIORITY
#define USE_FUNC_GCB_TOP_OF_WAIT_QUEUE

/*  */
#define USE_FUNC_SET_REG
#define USE_FUNC_GET_REG

/* memory concerning */
#define USE_FUNC_APPENDFREEAREABOUND
#define USE_FUNC_GET_BLK
#define USE_FUNC_REL_BLK
#define USE_FUNC_SEARCHFREEAREA
#define USE_FUNC_APPENDFREEAREA
#define USE_FUNC_REMOVEFREEQUE
#define USE_FUNC_INSERTAREAQUE
#define USE_FUNC_REMOVEAREAQUE
#if USE_IMALLOC
#define USE_FUNC_IMACB
#define USE_FUNC_IMALLOC
#define USE_FUNC_ICALLOC
#define USE_FUNC_IFREE
#define USE_FUNC_INIT_IMALLOC
#endif /* USE_IMALLOC */

#endif /* _UTK_CONFIG_FUNC_H_ */
