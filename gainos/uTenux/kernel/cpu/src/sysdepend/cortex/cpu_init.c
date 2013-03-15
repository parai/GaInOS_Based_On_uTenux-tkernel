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
 *	 File Name      : cpu_init.c
 *	 Create Date    : 2009/12/27-2012/6/10
 *	 Author	        : WangShb
 *	 Description    : CPU-Dependent Initialization/Finalization.
 *-------------------------------------------------------------------------------
 */

#include "kernel.h"
#include "task.h"
#include "cpu_insn.h"
#include "tkdev_conf.h"


/* Temporal stack used when 'dispatch_to_schedtsk' is called */
Noinit(EXPORT	UB	knl_tmp_stack[TMP_STACK_SZ]);

/*
 * CPU-dependent initialization
 */
EXPORT ER knl_cpu_initialize( void )
{
#if USE_TRAP
IMPORT void knl_dispatch_entry( void );		/* Dispatcher call */
IMPORT void tk_ret_int_impl( void );		/* 'tk_ret_int()' only call */

	/* Register exception handler used on OS */
	knl_define_inthdr(SWI_RETINT,   tk_ret_int_impl);
#if USE_DBGSPT
IMPORT void knl_call_dbgspt( void );		/* Debugger support call */
	knl_define_inthdr(SWI_DEBUG,    knl_call_dbgspt);
#endif
#endif /* USE_TRAP */

#if USE_TRAP
IMPORT void knl_call_entry( void );			/* System call */
	knl_define_inthdr(SWI_SVC,      knl_call_entry);
#endif

	return E_OK;
}

#if USE_CLEANUP
/*
 * CPU-dependent finalization
 */
EXPORT void knl_cpu_shutdown( void )
{
}
#endif /* USE_CLEANUP */
