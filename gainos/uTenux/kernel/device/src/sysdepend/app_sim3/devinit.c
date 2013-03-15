/*
 *------------------------------------------------------------------------------
 *    Device
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
 *	 File Name      : devinit.c
 *	 Create Date    : 2009/12/27-2013/1/16
 *	 Author	        : Wangxd-dengjk
 *	 Description    : Device-Dependent Initialization(AT91SAM3).
 *-------------------------------------------------------------------------------
 */

#include "sysinit.h"
#include "kernel.h"
#include <tk/sysdef.h>
#include <sys/sysinfo.h>
#include <libstr.h>


EXPORT	W	knl_taskindp = 0;
Noinit(EXPORT	UW	knl_taskmode);

/* ------------------------------------------------------------------------ */

/*
 * Initialization before micro T-Kernel starts
 */

EXPORT ER knl_init_device( void )
{
	return E_OK;
}

/* ------------------------------------------------------------------------ */
/*
 * Start processing after T-Kernel starts
 *	Called from the initial task contexts.
 */
EXPORT ER knl_start_device( void )
{
	return E_OK;
}

#if USE_CLEANUP
/* ------------------------------------------------------------------------ */
/*
 * System finalization
 *	Called just before system shutdown.
 *	Execute finalization that must be done before system shutdown.
 */
EXPORT ER knl_finish_device( void )
{
	return E_OK;
}

/* ------------------------------------------------------------------------ */
/*
 *	Re-starting processing
 */

/*
 * Re-starting processing
 *	mode = -1		Reset and re-start	(cold boot)
 *	mode = -2		Re-start		(warm boot)
 *	mode = -3		Reboot			(normal boot)
 *	mode = 0xFFhhmmss	Re-start at hh:mm:ss
 *				0 <= hh < 24, 0 <= mm,ss < 60
 */
EXPORT ER knl_restart_device( W mode )
{
	if ( mode == -1 ) {
		/* Reset and re-start (cold boot) */
#if USE_KERNEL_MESSAGE
		tm_putstring((UB*)"\n<< SYSTEM RESTART >>\n");
#endif
		tm_exit(-1);  /* no return */
		return E_OBJ;
	}

	if ( mode == -3 ) {
		/* Reboot (normal boot) */
#if USE_KERNEL_MESSAGE
		tm_putstring((UB*)"\n<< SYSTEM REBOOT >>\n");
#endif
		return E_NOSPT;
	}

	if ( mode == -2 ) {
		return E_NOSPT; /* Unsupported */
	}

	if ( (mode & 0xff000000U) == 0xff000000U ) {
		/* Re-start at specified time */
		return E_NOSPT;	/* Unsupported */
	}

	return E_PAR;
}
#endif /* USE_CLEANUP */
