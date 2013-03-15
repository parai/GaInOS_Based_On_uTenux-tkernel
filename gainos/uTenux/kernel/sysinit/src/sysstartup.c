/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2008 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.00
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2008/02/25.
 *
 *----------------------------------------------------------------------
 */

/*
 *	sysstartup.c (sysinit)
 *	Start/Stop System
 */

#include "sysinit.h"
#include "kernel.h"

/*
 * Manager/Driver
 */
IMPORT ER knl_init_Imalloc( void );			/* Internal memory allocation */

/* ------------------------------------------------------------------------ */

/*
 * Initialize sequence before T-Kernel starts
 */
EXPORT void knl_init_system( void )
{
	ER	ercd;

	/* Platform dependent initialize sequence */
	ercd = knl_init_device();

	if ( ercd < E_OK ) {
		goto err_ret;
	}
	/* Initialize Imalloc */
#if USE_IMALLOC

	ercd = knl_init_Imalloc();

	if ( ercd < E_OK ) {
		goto err_ret;
	}
#endif /* USE_IMALLOC */

	return;

err_ret:
#if USE_KERNEL_MESSAGE
	tm_putstring((UB*)"!ERROR! init_kernel\n");
#endif
	tm_monitor(); /* Stop */
}

/*
 * Start system
 */
EXPORT void knl_start_system( void )
{
	ER	ercd;

	/* Start system dependent sequence */
	ercd = knl_start_device();

	if ( ercd < E_OK ) {
		goto err_ret;
	}

	return;

err_ret:
#if USE_KERNEL_MESSAGE
	tm_putstring((UB*)"!ERROR! start_system\n");
#endif
	tm_monitor();	/* Stop */
}

#if USE_CLEANUP
/*
 * Stop system
 */
EXPORT void knl_shutdown_system( INT fin )
{
	/* Platform dependent finalize sequence */
	knl_finish_device();

	/* Shutdown message output */
#if USE_KERNEL_MESSAGE
	if ( fin >= 0 ) {
	  tm_putstring((UB*)"\n<< SYSTEM SHUTDOWN >>\n");
	}
#endif

	if ( fin < 0 ) {
		/* Re-start sequence (platform dependent) */
		knl_restart_device(fin);
	}

	/* Stop system */
	knl_t_kernel_exit();
}
#endif /* USE_CLEANUP */
