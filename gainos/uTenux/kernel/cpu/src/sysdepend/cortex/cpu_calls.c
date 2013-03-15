/*
 *------------------------------------------------------------------------------
 *    Cpu
 *
 *    Copyright (C) 2008-2013 by Dalian uLoong Co.,Ltd. All rights reserved.
 *
 *    This program is open source software; developer can redistribute it and/or
 *    modify it under the terms of the U-License as published by the T-Engine China
 *    Open Source Society; either version 1 of the License, or (at developer option)
 *    any later Version.
 *
 *    This program is distributed in the hope that it will be useful,but WITHOUT ANY
 *    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 *    A PARTICULAR PURPOSE.  See the U-License for more details.
 *
 *    Developer should have received a copy of the U-License along with this program;
 *    if not, download from www.tecoss.org(the web page of the T-Engine China Open
 *    Source Society).
 *
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : cpu_calls.c
 *	 Create Date    : 2009/12/27-2013/1/10
 *	 Author	        : WangShb
 *	 Description    : CPU-Dependent System Call.
 *-------------------------------------------------------------------------------
 */

/** [BEGIN Common Definitions] */
#include "kernel.h"
#include "task.h"
#include "check.h"
#include "cpu_task.h"

#include <sys/sysinfo.h>
#include <tk/sysdef.h>
#include "cpu_insn.h"
#include "cpu_calls.h"
/** [END Common Definitions] */

#ifdef USE_FUNC_TK_DIS_DSP
/*
 * Dispatch enable/disable 
 */
SYSCALL ER tk_dis_dsp_impl( void )
{
	CHECK_CTX(!in_loc());

	knl_dispatch_disabled = DDS_DISABLE;

	return E_OK;
}
#endif /* USE_FUNC_TK_DIS_DSP */

#ifdef USE_FUNC_TK_ENA_DSP
/*
 * Dispatch enable 
 */
SYSCALL ER tk_ena_dsp_impl( void )
{
	CHECK_CTX(!in_loc());

	knl_dispatch_disabled = DDS_ENABLE;
	if ( knl_ctxtsk != knl_schedtsk ) {
		knl_dispatch();
	}

	return E_OK;
}
#endif /* USE_FUNC_TK_ENA_DSP */

/* ------------------------------------------------------------------------ */

/*
 * High level programming language
 */

#ifdef USE_FUNC_HLL_INTHDR
/* High level programming language interrupt handler entry */
Noinit(EXPORT FP knl_hll_inthdr[N_INTVEC]);
#endif /* USE_FUNC_HLL_INTHDR */

#ifdef USE_FUNC_TK_DEF_INT
IMPORT FP knl_hll_inthdr[];

/* High level programming language routine (Interrupt) */
IMPORT void knl_inthdr_startup();

/* High level programming language routine (Exception) */
IMPORT void knl_exchdr_startup();

/* Low level programming language routine (defalut Interrupt and Exception) */
IMPORT void default_handler(void);

/*
 * Interrupt handler definition
 */
SYSCALL ER tk_def_int_impl( UINT dintno, T_DINT *pk_dint )
{
	FP	inthdr;

	CHECK_PAR(dintno < N_INTVEC);
#if !USE_HLL_INTHDR
	CHECK_PAR((pk_dint->intatr & TA_HLNG) == 0);
#endif

	if ( pk_dint != NULL ) {
		/* Set interrupt handler */
		CHECK_RSATR(pk_dint->intatr, TA_HLNG);

		inthdr = pk_dint->inthdr;

		BEGIN_CRITICAL_SECTION;
#if USE_HLL_INTHDR
		if ( (pk_dint->intatr & TA_HLNG) != 0 ) {
			knl_hll_inthdr[dintno] = inthdr;
			inthdr = (dintno < 0x10U) ? knl_exchdr_startup:
					                    knl_inthdr_startup;
		}
#endif
		knl_define_inthdr(dintno, inthdr);
		END_CRITICAL_SECTION;
	} else {
		/* Clear interrupt handler */
		BEGIN_CRITICAL_SECTION;
		knl_define_inthdr(dintno, default_handler);
#if USE_HLL_INTHDR
		knl_hll_inthdr[dintno] = NULL;
#endif
		END_CRITICAL_SECTION;
	}

	return E_OK;
}
#endif /* USE_FUNC_TK_DEF_INT */

/* ------------------------------------------------------------------------ */

#ifdef USE_FUNC_SET_REG
/*
 * Set task register contents
 */
EXPORT void knl_set_reg( TCB *tcb, T_REGS *regs, T_EIT *eit, T_CREGS *cregs )
{
	SStackFrame	*ssp;

	ssp = tcb->tskctxb.ssp;

	if ( cregs != NULL ) {
		ssp = cregs->ssp;
	}

	if ( regs != NULL ) {
		ssp->r0         = regs->r[0];
		ssp->r1         = regs->r[1];
		ssp->r2         = regs->r[2];
		ssp->r3         = regs->r[3];
		ssp->r4         = regs->r[4];
		ssp->r5         = regs->r[5];
		ssp->r6         = regs->r[6];
		ssp->r7         = regs->r[7];
		ssp->r8         = regs->r[8];
		ssp->r9         = regs->r[9];
		ssp->r10        = regs->r[10];
		ssp->r11        = regs->r[11];
		ssp->r12        = regs->r[12];
		ssp->lr         = regs->lr;
	}

	if ( eit != NULL ) {
		ssp->pc         = eit->pc;
		ssp->xpsr       = eit->psr;
		ssp->taskmode   = eit->taskmode;
	}

	if ( cregs != NULL ) {
		tcb->tskctxb.ssp  = cregs->ssp;
	}
}
#endif /* USE_FUNC_SET_REG */


#ifdef USE_FUNC_TK_SET_REG
/*
 * Set task register contents
 */
SYSCALL ER tk_set_reg_impl( ID tskid, T_REGS *pk_regs, T_EIT *pk_eit, T_CREGS *pk_cregs )
{
	TCB		*tcb;
	ER		ercd = E_OK;

	CHECK_INTSK();
	CHECK_TSKID(tskid);
	CHECK_NONSELF(tskid);

	tcb = get_tcb(tskid);

	BEGIN_CRITICAL_SECTION;
	if ( tcb->state == TS_NONEXIST ) {
		ercd = E_NOEXS;
	} else {
		knl_set_reg(tcb, pk_regs, pk_eit, pk_cregs);
	}
	END_CRITICAL_SECTION;

	return ercd;
}
#endif /* USE_FUNC_TK_SET_REG */

#ifdef USE_FUNC_GET_REG
/*
 * Get task register contents
 */
EXPORT void knl_get_reg( TCB *tcb, T_REGS *regs, T_EIT *eit, T_CREGS *cregs )
{
	SStackFrame	*ssp;

	ssp = tcb->tskctxb.ssp;

	if ( regs != NULL ) {
		regs->r[0]    = ssp->r0;
		regs->r[1]	  = ssp->r1;
		regs->r[2]	  = ssp->r2;
		regs->r[3]	  = ssp->r3;
		regs->r[4]	  = ssp->r4;
		regs->r[5]	  = ssp->r5;
		regs->r[6]	  = ssp->r6;
		regs->r[7]	  = ssp->r7;
		regs->r[8]	  = ssp->r8;
		regs->r[9]	  = ssp->r9;
		regs->r[10]	  = ssp->r10;
		regs->r[11]	  = ssp->r11;
		regs->r[12]   = ssp->r12;
		regs->lr      = ssp->lr;
	}

	if ( eit != NULL ) {
		eit->pc       = ssp->pc;
		eit->psr      = ssp->xpsr;
		eit->taskmode = ssp->taskmode;
	}

	if ( cregs != NULL ) {
		cregs->ssp    = tcb->tskctxb.ssp;
		cregs->usp    = tcb->tskctxb.ssp;
	}
}
#endif /* USE_FUNC_GET_REG */

#ifdef USE_FUNC_TK_GET_REG
/*
 * Get task register contents
 */
SYSCALL ER tk_get_reg_impl( ID tskid, T_REGS *pk_regs, T_EIT *pk_eit, T_CREGS *pk_cregs )
{
	TCB		*tcb;
	ER		ercd = E_OK;

	CHECK_INTSK();
	CHECK_TSKID(tskid);
	CHECK_NONSELF(tskid);

	tcb = get_tcb(tskid);

	BEGIN_CRITICAL_SECTION;
	if ( tcb->state == TS_NONEXIST ) {
		ercd = E_NOEXS;
	} else {
		knl_get_reg(tcb, pk_regs, pk_eit, pk_cregs);
	}
	END_CRITICAL_SECTION;

	return ercd;
}
#endif /* USE_FUNC_TK_GET_REG */

/* ------------------------------------------------------------------------ */
/*
 *	Debugger support function
 */
#if USE_DBGSPT

#ifdef USE_FUNC_TD_SET_REG
/*
 * Set task register
 */
SYSCALL ER td_set_reg_impl( ID tskid, T_REGS *regs, T_EIT *eit, T_CREGS *cregs )
{
	TCB	*tcb;
	ER	ercd = E_OK;

	CHECK_TSKID(tskid);

	tcb = get_tcb(tskid);
	if ( tcb == knl_ctxtsk ) {
		return E_OBJ;
	}

	BEGIN_DISABLE_INTERRUPT;
	if ( tcb->state == TS_NONEXIST ) {
		ercd = E_NOEXS;
	} else {
		knl_set_reg(tcb, regs, eit, cregs);
	}
	END_DISABLE_INTERRUPT;

	return ercd;
}
#endif /* USE_FUNC_TD_SET_REG */

#ifdef USE_FUNC_TD_GET_REG
/*
 * Get task register
 */
SYSCALL ER td_get_reg_impl( ID tskid, T_REGS *regs, T_EIT *eit, T_CREGS *cregs )
{
	TCB	*tcb;
	ER	ercd = E_OK;

	CHECK_TSKID(tskid);

	tcb = get_tcb(tskid);
	if ( tcb == knl_ctxtsk ) {
		return E_OBJ;
	}

	BEGIN_DISABLE_INTERRUPT;
	if ( tcb->state == TS_NONEXIST ) {
		ercd = E_NOEXS;
	} else {
		knl_get_reg(tcb, regs, eit, cregs);
	}
	END_DISABLE_INTERRUPT;

	return ercd;
}
#endif /* USE_FUNC_TD_GET_REG */

#endif /* USE_DBGSPT */
