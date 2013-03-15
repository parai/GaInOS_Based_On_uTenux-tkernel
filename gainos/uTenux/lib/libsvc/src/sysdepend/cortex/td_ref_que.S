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
 *	 File Name      : td_ref_que.S
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
	.global	Csym(td_acp_que)
	.type	Csym(td_acp_que), function
Csym(td_acp_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_ACP_QUE
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
	.global	Csym(td_cal_que)
	.type	Csym(td_cal_que), function
Csym(td_cal_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_CAL_QUE
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
	.global	Csym(td_flg_que)
	.type	Csym(td_flg_que),function
Csym(td_flg_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_FLG_QUE
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
	.global	Csym(td_mbx_que)
	.type	Csym(td_mbx_que),function
Csym(td_mbx_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_MBX_QUE
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
	.global	Csym(td_mpf_que)
	.type	Csym(td_mpf_que),function
Csym(td_mpf_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_MPF_QUE
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
	.thumb_func
	.global	Csym(td_mpl_que)
	.type	Csym(td_mpl_que),function
Csym(td_mpl_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_MPL_QUE
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
	.global	Csym(td_mtx_que)
	.type	Csym(td_mtx_que),function
Csym(td_mtx_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_MTX_QUE
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
	.global	Csym(td_rdy_que)
	.type	Csym(td_rdy_que),function
Csym(td_rdy_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_RDY_QUE
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
	.global	Csym(td_rmbf_que)
	.type	Csym(td_rmbf_que),function
Csym(td_rmbf_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_RMBF_QUE
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
	.global	Csym(td_sem_que)
	.type	Csym(td_sem_que),function
Csym(td_sem_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_SEM_QUE
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
	.global	Csym(td_smbf_que)
	.type	Csym(td_smbf_que),function
Csym(td_smbf_que):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_SMBF_QUE
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
