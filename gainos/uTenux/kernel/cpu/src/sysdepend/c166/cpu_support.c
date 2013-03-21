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
 *    CPU:        C166
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
IMPORT void knl_low_pow( void );
IMPORT UINT  knl_taskmode;
IMPORT	INT  knl_taskindp;
IMPORT 	 UB	 knl_tmp_stack[TMP_STACK_SZ];
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
static void l_dispatch0(void)
{
}
void knl_dispatch_to_schedtsk(void)
{
}

void knl_dispatch_entry(void)
{
   	
}
IMPORT void knl_timer_handler( void );
void OSTickISR(void)
{  		
}