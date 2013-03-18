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
 *	 File Name      : cpu_support.c
 *   Create Date    : 2013/3/15-2013/3/17
 *   Author         : Fan Wang(parai)
 *	 Description    : CPU-Dependent dispatcher Operation.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/errno.h>
#include <tk/sysdef.h>
#include <tk/asm.h>
#include <sys/sysinfo.h>

#include "config.h"
#include "utk_config.h"
#if USE_TRAP | (USE_DBGSPT & USE_HOOK_TRACE)
#include "isysconf.h"
#endif
#include "typedef.h"
#include "tkdev_conf.h"
#include "offset.h"
IMPORT INT	knl_dispatch_disabled;
IMPORT void	*knl_ctxtsk;
IMPORT void	*knl_schedtsk;
IMPORT void  knl_low_pow( void );
IMPORT UINT  knl_taskmode;
IMPORT	INT  knl_taskindp;
IMPORT 	 UB	 knl_tmp_stack[TMP_STACK_SZ];
IMPORT   UINT l_sp_offset;

EXPORT asm UINT knl_getPRIMASK ( void )
{
nofralloc
	mfmsr   r3
	blr		
}
#if USE_DBGSPT & USE_HOOK_TRACE
LOCAL void hook_stop_jmp(void)
{
}
LOCAL void hook_exec_jmp(void)
{
}
#endif
/*
 *    Function Name : knl_dispatch_to_schedtsk,knl_dispatch_entry,_ret_int_dispatch
 *    Create Date   : 2009/12/27-2012/11/22
 *    Author        : wangshb
 *    Description   : Dispatcher,save contexts 'ssp' to TCB.include three parts.
 *                    1.dispatch_to_schedtsk:
 *                         Throw away the current contexts and forcibly dispatch to
 *                         'schedtsk.'
 *                         Called directly by jump (bx) but do not return.
 *                         Called on the undefined stack state (undefined 'ssp').
 *                         Called on the interrupt disable state.
 *                    2.dispatch_entry:
 *                         Normal dispatch processing.
 *                         Called by PendSV exception.
 *                    3._ret_int_dispatch:
 *                         Called when dispatch is required by 'tk_ret_int().'
 *    Param	        : none
 *    Return Code   : none
 */
asm static void l_dispatch0(void)
{
nofralloc
#if USE_DBGSPT & USE_HOOK_TRACE
	bl hook_stop_jmp		    /* Hook processing */
ret_hook_stop:
#endif

  	lis  r5,knl_schedtsk@h;    
  	ori  r5,r5,knl_schedtsk@l;  /* R5 = &schedtsk */
	
l_dispatch1:
	wrteei  0;		/* Interrupt disable */ 
	
	lwz   r8,0(r5)
  	cmpwi r8,0; 	/* Is there 'schedtsk'? */
  	bne	 l_dispatch2;
	/* Because there is no task that should be executed,
  	 * move to the power-saving mode */
  	//bl   knl_low_pow;
	
  	wrteei  1;		/* Interrupt enable */ 
  	b	 l_dispatch1 

l_dispatch2:                   /* Switch to 'schedtsk' */
	lis  r6,knl_ctxtsk@h;
	stw  r8,knl_ctxtsk@l(r6);  /* ctxtsk = schedtsk */
	
	lis    r6,l_sp_offset@h;
	lwz    r6,l_sp_offset@l(r6);
	lwzx   r1, r8,r6;     /* Restore 'ssp' from TCB */	

#if USE_DBGSPT & USE_HOOK_TRACE
	bl hook_exec_jmp		    /* Hook processing */
ret_hook_exec:
#endif

	li     r11,0
	lis    r12,knl_dispatch_disabled@h
	stw    r11,knl_dispatch_disabled@l(r12)  /* Dispatch enable */
	
	lwz    r11,XTMODE(r1);
	lis    r12,knl_taskmode@h;
	stw    r11,knl_taskmode@l(r12);  /* restore taskmode */  
	
  
	lwz   r3,XR3(r1);
    OS_RESTORE_R4_TO_R12();   
	OS_RESTORE_R14_TO_R31();   /* all GPRs restored */
	OS_RESTORE_SPFRS();        /* all SPFRs restored */	
	/* restore R0 */
	lwz   r0,XR0(r1);
    addi  r1,r1, STACK_FRAME_SIZE
  	rfi
}

asm void knl_dispatch_to_schedtsk(void)
{
nofralloc
	wrteei  0;		/* Interrupt disable */ 
	lis		r1,knl_tmp_stack@h			
	ori    r1,r1,knl_tmp_stack@l
	addi	r1,r1,TMP_STACK_SZ	/* Set temporal stack */
	/* as curtsk is no longer running,so no need to care about the context */
	li     r11,1
	lis    r12,knl_dispatch_disabled@h
	stw    r11,knl_dispatch_disabled@l(r12)  /* Dispatch disable */
	li	   r11,0
	lis	   r12,knl_ctxtsk@h
	stw    r11,knl_ctxtsk@l(r12)             /* ctxtsk = NULL */
	wrteei  1;		                         /* Interrupt enable */ 
	b	   l_dispatch0  	  
}
IMPORT void knl_dispatch_entry(void);
EXPORT __asm void knl_install_swi_handler()
{
nofralloc	
    lis     r0, knl_dispatch_entry@h
    ori     r0, r0, knl_dispatch_entry@l
    /* IVOR8 System call interrupt (SPR 408) */
    mtivor8 r0	
    blr
}

IMPORT void knl_timer_handler( void );
#pragma section RX ".__exception_handlers"
#pragma push /* Save the current state */
__declspec (section ".__exception_handlers") extern long EXCEPTION_HANDLERS;  
#pragma force_active on
#pragma function_align 16 /* We use 16 bytes alignment for Exception handlers */
__declspec(interrupt)
__declspec (section ".__exception_handlers")
asm void knl_dispatch_entry(void)
{
nofralloc
	subi  r1,r1,STACK_FRAME_SIZE
	stw   r0,XR0(r1);
	stw   r3,XR3(r1);
_ret_int_dispatch:
	li     r0,1
	lis    r3,knl_dispatch_disabled@h
	stw    r0,knl_dispatch_disabled@l(r12)  /* Dispatch disable */

	wrteei  1;		                        /* Interrupt enable */ 
	OS_SAVE_R4_TO_R12();   
	OS_SAVE_R14_TO_R31();   /* all GPRs saved */
	OS_SAVE_SPFRS();        /* all SPFRs saved */
	
	lis    r0,knl_taskmode@h;
	lwz    r0,knl_taskmode@l(r0);
	stw    r0,XTMODE(r1);    /* save taskmode */

	lis  r5,knl_ctxtsk@h;
	lwz  r5,knl_ctxtsk@l(r5);
			
	lis    r6,l_sp_offset@h;
	lwz    r6,l_sp_offset@l(r6);
	stwx   r1, r5,r6;     /* Save 'ssp' to TCB */	
	
	li	   r11,0
	lis	   r12,knl_ctxtsk@h
	stw    r11,knl_ctxtsk@l(r12)             /* ctxtsk = NULL */
	b	   l_dispatch0  	  		    	
}

asm void OSTickISR(void)
{ 
nofralloc 
	subi  r1,r1,STACK_FRAME_SIZE
	stw   r0,XR0(r1);
	stw   r3,XR3(r1);
	OS_SAVE_R4_TO_R12();   
	OS_SAVE_R14_TO_R31();   /* all GPRs saved */
	OS_SAVE_SPFRS();        /* all SPFRs saved */
	lis    r0,knl_taskmode@h;
	lwz    r0,knl_taskmode@l(r0);
	stw    r0,XTMODE(r1);    /* save taskmode */	
	
	lis    r3, 0x0800;   // load r3 with TSR[DIS] bit (0x08000000)
    mtspr  TSR,r3;       // clear TSR[DIS] bit
 
    wrteei  1;      //enable interrupt
    bl knl_timer_handler;

	lwz    r11,XTMODE(r1);
	lis    r12,knl_taskmode@h;
	stw    r11,knl_taskmode@l(r12);  /* restore taskmode */  
	
	
    OS_RESTORE_R4_TO_R12();   
	OS_RESTORE_R14_TO_R31();   /* all GPRs restored */
	OS_RESTORE_SPFRS();        /* all SPFRs restored */	
	lwz   r3,XR3(r1);
	lwz   r0,XR0(r1);
    addi  r1,r1, STACK_FRAME_SIZE
  	rfi
}

#pragma force_active off
#pragma pop