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
 *	 File Name      : cpu_support.S
 *	 Create Date    : 2009/12/27-2013/1/10
 *	 Author	        : WangShb-wangshb
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
#include "mc9s12dp512.h"
IMPORT INT	knl_dispatch_disabled;
IMPORT void	*knl_ctxtsk;
IMPORT void	*knl_schedtsk;
IMPORT UW  knl_taskmode;
IMPORT	W  knl_taskindp;
IMPORT void knl_low_pow( void );
IMPORT UB l_sp_offset;
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
#pragma CODE_SEG __NEAR_SEG NON_BANKED
static void l_dispatch0(void)
{
    #if USE_DBGSPT & USE_HOOK_TRACE
    	hook_stop_jmp();
    #endif
    l_dispatch1:
    asm sei;   //disable interrupt
    if(knl_schedtsk==(void *)0)
    {
        knl_low_pow();
        asm cli;  //enable interrupt
        goto l_dispatch1;
    }
    l_dispatch2:
    knl_ctxtsk=knl_schedtsk;
    #if USE_DBGSPT & USE_HOOK_TRACE
	hook_exec_jmp();		    /* Hook processing */
	#endif
	knl_dispatch_disabled=0;    /* Dispatch enable */
	/* Context restore */
	asm   ldx  knl_ctxtsk;
	asm   ldab l_sp_offset;
	asm   lds  b,x;       /* Restore 'ssp' from TCB */
	asm   pula
    asm   staa	$30	      /* restore PPAGE */
    asm   puld;
    asm   std   knl_taskmode:2
    asm   puld;
    asm   std   knl_taskmode  /* restore knl_taskmode */
    asm   rti;   
}
void knl_dispatch_to_schedtsk(void)
{
    knl_dispatch_disabled=1;    /* Dispatch disable */ 
    knl_ctxtsk=(void *)0;
    asm sei; 
    asm jmp l_dispatch0;
}
interrupt 4 void knl_dispatch_entry(void)
{
_ret_int_dispatch:
    knl_dispatch_disabled=1;    /* Dispatch disable */ 
    asm   ldd   knl_taskmode:2
    asm   pshd;
    asm   ldd   knl_taskmode  
    asm   pshd;                 /* save knl_taskmode */
    asm   ldaa	$30		        
	asm   psha                  /* save ppage */
	asm   ldx  knl_ctxtsk;
	asm   ldab l_sp_offset;
	asm   sts  b,x;            /* save 'ssp' to TCB */
	knl_ctxtsk=(void*)0;
	asm jmp l_dispatch0;  	    	
}
IMPORT void knl_timer_handler( void );
interrupt 7 void OSTickISR(void)
{  
    CRGFLG &=0xEF;			// clear the interrupt flag  
	asm cli;     /* enable interrupt */
    asm call knl_timer_handler; 		
}
#pragma CODE_SEG DEFAULT