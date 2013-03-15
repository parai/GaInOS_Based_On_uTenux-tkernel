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
 *	sysmain.h (sysmain)
 *	Kernel Main
 */

#ifndef _SYSMAIN_
#define _SYSMAIN_

#include <basic.h>
#include <tk/tkernel.h>
#include <tm/tmonitor.h>

/* Boot message */
#define BOOT_MESSAGE \
	"\n\0"

/*
 * User main
 */
IMPORT INT usermain( void );

#endif /* _SYSMAIN_ */
