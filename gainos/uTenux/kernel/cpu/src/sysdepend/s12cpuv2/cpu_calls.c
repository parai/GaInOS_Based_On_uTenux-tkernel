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
 *    CPU:        MC9S12
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *
 *	 File Name      : cpu_calls.c
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
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
EXPORT UB l_sp_offset = (UB)&(((TCB*)0)->tskctxb);

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
	}

	if ( eit != NULL ) {
	}

	if ( cregs != NULL ) {
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
	}

	if ( eit != NULL ) {
		eit->pc       = ssp->pc;
		eit->taskmode = ssp->taskmode;
	}

	if ( cregs != NULL ) {
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
