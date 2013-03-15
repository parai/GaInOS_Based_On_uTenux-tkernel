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
 *	 File Name      : td_lst_oid.S
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
	.global	Csym(td_lst_alm)
	.type	Csym(td_lst_alm),function
Csym(td_lst_alm):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_ALM
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
	.global	Csym(td_lst_cyc)
	.type	Csym(td_lst_cyc),function
Csym(td_lst_cyc):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_CYC
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
	.global	Csym(td_lst_flg)
	.type	Csym(td_lst_flg),function
Csym(td_lst_flg):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_FLG
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_DEBUG
#else
	bl   	Csym(knl_call_dbgspt)
#endif
	pop 	{r4}
	mov     lr,r4
	pop 	{r4}
	bx  	lr
#endif

#if USE_TRAP || (USE_DBGSPT && USE_HOOK_TRACE)
	.text
    .syntax unified
	.global	Csym(td_lst_mbf)
	.type	Csym(td_lst_mbf),function
Csym(td_lst_mbf):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_MBF
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
	.global	Csym(td_lst_mbx)
	.type	Csym(td_lst_mbx),function
Csym(td_lst_mbx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_MBX
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
	.global	Csym(td_lst_mpf)
	.type	Csym(td_lst_mpf),function
Csym(td_lst_mpf):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_MPF
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
	.global	Csym(td_lst_mpl)
	.type	Csym(td_lst_mpl),function
Csym(td_lst_mpl):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_MPL
	mov     ip,r3
	pop     {r3}
#if USE_TRAP
    svc		SWI_SVC
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
	.global	Csym(td_lst_mtx)
	.type	Csym(td_lst_mtx),function
Csym(td_lst_mtx):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_MTX
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
	.global	Csym(td_lst_por)
	.type	Csym(td_lst_por),function
Csym(td_lst_por):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_POR
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
	.global	Csym(td_lst_sem)
	.type	Csym(td_lst_sem),function
Csym(td_lst_sem):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_SEM
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
	.global	Csym(td_lst_tsk)
	.type	Csym(td_lst_tsk),function
Csym(td_lst_tsk):
	push  	{r4}
	add     r4, sp, #4
	push  	{lr}
	push    {r3}
	ldr	    r3, =TDFN_LST_TSK
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
