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
 *    Version:    1.0.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : tk_svc_tsk.S
 *	 Create Date    : 2009/7/27-2012/9/24
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel SVC interface library .
 *                    created from /usr/local/te/include/tk/syscall.h
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/sysdef.h>
#include <sys/svc/tkfncd.h>
#include "utk_config.h"

    .syntax unified

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_can_wup)
	.type	Csym(tk_can_wup), %function
Csym(tk_can_wup):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_CAN_WUP
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_chg_pri)
	.type	Csym(tk_chg_pri), %function
Csym(tk_chg_pri):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_CHG_PRI
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_cre_tsk)
	.type	Csym(tk_cre_tsk), %function
Csym(tk_cre_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_CRE_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_del_tsk)
	.type	Csym(tk_del_tsk), %function
Csym(tk_del_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_DEL_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_dly_tsk)
	.type	Csym(tk_dly_tsk), %function
Csym(tk_dly_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_DLY_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_exd_tsk)
	.type	Csym(tk_exd_tsk), %function
Csym(tk_exd_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_EXD_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_ext_tsk)
	.type	Csym(tk_ext_tsk), %function
Csym(tk_ext_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_EXT_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_frsm_tsk)
	.type	Csym(tk_frsm_tsk), %function
Csym(tk_frsm_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_FRSM_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_get_reg)
	.type	Csym(tk_get_reg), %function
Csym(tk_get_reg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_GET_REG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_ref_tsk)
	.type	Csym(tk_ref_tsk), %function
Csym(tk_ref_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_REF_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_rel_wai)
	.type	Csym(tk_rel_wai), %function
Csym(tk_rel_wai):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_REL_WAI
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_rsm_tsk)
	.type	Csym(tk_rsm_tsk), %function
Csym(tk_rsm_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_RSM_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_set_reg)
	.type	Csym(tk_set_reg), %function
Csym(tk_set_reg):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_SET_REG
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_slp_tsk)
	.type	Csym(tk_slp_tsk), %function
Csym(tk_slp_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_SLP_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_sta_tsk)
	.type	Csym(tk_sta_tsk), %function
Csym(tk_sta_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_STA_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_sus_tsk)
	.type	Csym(tk_sus_tsk), %function
Csym(tk_sus_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_SUS_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_ter_tsk)
	.type	Csym(tk_ter_tsk), %function
Csym(tk_ter_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_TER_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
	.balign	4
	.global	Csym(tk_wup_tsk)
	.type	Csym(tk_wup_tsk), %function
Csym(tk_wup_tsk):
	stmfd	sp!, {r4}
	add	    r4, sp, #4
	stmfd	sp!, {lr}
	ldr	    ip, =TFN_WUP_TSK
#if USE_TRAP
	swi	    SWI_SVC
#else
	bl	    Csym(knl_call_entry)
#endif
	ldmfd	sp!, {lr}
	ldmfd	sp!, {r4}
	bx	    lr
#endif

	.end
