/*
 *------------------------------------------------------------------------------
 *    Libsvc
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
 *    CPU:        ARM7&9
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : td_ref_que.S
 *	 Create Date    : 2009/7/27-2012/9/24
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel SVC interface library.
 *                    created from /usr/local/te/include/tk/dbgspt.h
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>
#include <sys/svc/tdfncd.h>
#include "utk_config.h"

    .syntax unified

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global Csym(td_acp_que)
	.type	Csym(td_acp_que), %function
Csym(td_acp_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_ACP_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_cal_que)
	.type	Csym(td_cal_que), %function
Csym(td_cal_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_CAL_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_flg_que)
	.type	Csym(td_flg_que), %function
Csym(td_flg_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_FLG_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_mbx_que)
	.type	Csym(td_mbx_que), %function
Csym(td_mbx_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_MBX_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_mpf_que)
	.type	Csym(td_mpf_que), %function
Csym(td_mpf_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_MPF_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_mpl_que)
	.type	Csym(td_mpl_que), %function
Csym(td_mpl_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_MPL_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_mtx_que)
	.type	Csym(td_mtx_que), %function
Csym(td_mtx_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_MTX_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_rdy_que)
	.type	Csym(td_rdy_que), %function
Csym(td_rdy_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_RDY_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_rmbf_que)
	.type	Csym(td_rmbf_que), %function
Csym(td_rmbf_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_RMBF_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_sem_que)
	.type	Csym(td_sem_que), %function
Csym(td_sem_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_SEM_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(td_smbf_que)
	.type	Csym(td_smbf_que), %function
Csym(td_smbf_que):
	stmfd	sp!, {lr}
	ldr	    ip, =TDFN_SMBF_QUE
#if USE_TRAP
	swi	    SWI_DEBUG
#else
	bl	    Csym(knl_call_dbgspt)
#endif
	ldmfd	sp!, {lr}
	bx	    lr
#endif

	.end
