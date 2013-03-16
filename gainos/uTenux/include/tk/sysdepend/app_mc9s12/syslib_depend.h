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
 *    CPU:        CORTEX M3
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : syslib_depend.h
 *	 Create Date    : 2009/12/27-2013/1/5
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel Library(tk/AT91SAM3).
 *-------------------------------------------------------------------------------
 */

#ifndef __TK_SYSLIB_DEPEND_H__
#define __TK_SYSLIB_DEPEND_H__

#include <tk/errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * CPU interrupt control
 *	'intsts' is the value of PRIMASK in CPU
 *	disint()  Set PRIMASK = 1 and return the original PRIMASK
 *		  to the return value.
 *	enaint()  Set PRIMASK = intsts, Do not change except
 *		  for PRIMASK
 *		  Return the original PRIMASK to the return value.
 */
IMPORT UB disint( void );
IMPORT void enaint( UB intsts );
#define DI(intsts)	    ( (intsts) = disint() )
#define EI(intsts)	    ( (void)enaint(intsts) )
#define isDI(intsts)	( ((intsts) & PMK_D) != 0 )


/* ------------------------------------------------------------------------ */

/*
 * I/O port access
 *	Only memory mapped I/O for Arm
 */
#define out_w(port,data)  *(_UW*)(port) = (data)
#define out_h(port,data ) *(_UH*)(port) = (data)
#define out_b(port,data ) *(_UB*)(port) = (data)

#define in_w(port) (*(_UW*)(port))
#define in_h(port) (*(_UH*)(port))
#define in_b(port) (*(_UB*)(port))

#ifdef __cplusplus
}
#endif
#endif /* __TK_SYSLIB_DEPEND_H__ */
