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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : td_ref_oid.S
 *	 Create Date    : 2009/12/27-2012/10/29
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel SVC interface library.
 *                    created from /usr/local/te/include/tk/dbgspt.h
 *-------------------------------------------------------------------------------
 */
#include <machine.h>
#include <tk/sysdef.h>
#include <sys/svc/tdfncd.h>
#include "utk_config.h"

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_alm)
	.type	Csym(td_ref_alm),function
Csym(td_ref_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_ALM
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_cyc)
	.type	Csym(td_ref_cyc),function
Csym(td_ref_cyc):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	ldr	    r3, =TDFN_REF_CYC
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_dsname)
	.type	Csym(td_ref_dsname),function
Csym(td_ref_dsname):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_DSNAME
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_flg)
	.type	Csym(td_ref_flg),function
Csym(td_ref_flg):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_FLG
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_mbf)
	.type	Csym(td_ref_mbf),function
Csym(td_ref_mbf):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_MBF
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_mbx)
	.type	Csym(td_ref_mbx),function
Csym(td_ref_mbx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_MBX
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl.w	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_mpf)
	.type	Csym(td_ref_mpf),function
Csym(td_ref_mpf):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_MPF
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_mpl)
	.type	Csym(td_ref_mpl),function
Csym(td_ref_mpl):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_MPL
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl.w	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_mtx)
	.type	Csym(td_ref_mtx),function
Csym(td_ref_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_MTX
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_por)
	.type	Csym(td_ref_por),function
Csym(td_ref_por):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_POR
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_sem)
	.type	Csym(td_ref_sem),function
Csym(td_ref_sem):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_SEM
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_sys)
	.type	Csym(td_ref_sys),function
Csym(td_ref_sys):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_SYS
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_ref_tsk)
	.type	Csym(td_ref_tsk),function
Csym(td_ref_tsk):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_REF_TSK
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl  	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

	.end
