/*
 *------------------------------------------------------------------------------
 *    Include/tk
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
 *    CPU:        AT91SAM7S256
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : asm_depend.h
 *	 Create Date    : 2009/7/27-2012/9/21
 *	 Author	        : WangShb
 *	 Description    : Assembler Macro(tk/AT91SAM7).
 *-------------------------------------------------------------------------------
 */

#ifndef __TK_ASM_DEPEND_H__
#define __TK_ASM_DEPEND_H__

/* ------------------------------------------------------------------------ */
/*
 *	Exception restore
 */

/*
 * Exception return
 */
 .macro EXC_RETURN
	.arm
	ldmfd	sp!, {ip}
	msr	spsr_fsxc, ip
	ldmfd	sp!, {ip, pc}^
 .endm

/* ------------------------------------------------------------------------ */
/*
 *	tk_ret_int() system call
 */

/*
 * Return from handler by tk_ret_int()
 *	mode	Handler exception mode (Available on all modes including FIQ)
 *
 *	Use from SVC mode.
 *
 *	State of handler exception mode stack at Macro call
 *		+---------------+
 *	sp  ->	|R3		|
 *		|SPSR		|
 *		|R12=ip		|
 *		|R14=lr		|
 *		+---------------+
 */
 .macro TK_RET_INT_FIQ mode
	.arm
	mov	r3, lr				// r3 = lr_svc
	msr	cpsr_c, #PSR_I|PSR_F|\mode	// Return to previous exception mode
	swp	r3, r3, [sp]			// Save lr_svc and restore r3
	swi	SWI_RETINT
 .endm

/* ------------------------------------------------------------------------ */
#endif /* __TK_ASM_DEPEND_H__ */
