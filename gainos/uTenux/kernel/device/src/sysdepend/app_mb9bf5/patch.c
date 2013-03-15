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
 *	 File Name      : patch.c
 *	 Create Date    : 2012/7/19-2012/7/19
 *	 Author	        : WangShb
 *	 Description    : System-dependent initialize process(MB9BF5).
 *-------------------------------------------------------------------------------
 */

#include <basic.h>
#include <tk/tkernel.h>
#include <tk/sysdef.h>
#include "patch.h"


#if USE_SYSDEPEND_PATCH1
/*
 * System-dependent processes (before start_system)
 */
EXPORT void sysdepend_patch1( void )
{
	/* Do nothing */
}
#endif

#if USE_SYSDEPEND_PATCH2
/*
 * System-dependent processes (after start_system)
 */
EXPORT void sysdepend_patch2( void )
{
	/* Do nothing */
}
#endif
