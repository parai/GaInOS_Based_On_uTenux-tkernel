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
 *	 Create Date    : 2012/7/9-2013/1/14
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel Library(tk/STM32F1).
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
IMPORT UINT disint( void );
IMPORT UINT enaint( UINT intsts );
#define DI(intsts)	    ( (intsts) = disint() )
#define EI(intsts)	    ( enaint(intsts) )
#define isDI(intsts)	( ((intsts) & PMK_D) != 0 )


/*
 * Interrupt vector
 *	The interrupt vector is the index number of the vector table.
 */
typedef UINT	INTVEC;

/* Convert interrupt vector number to interrupt definition number */
#define DINTNO(intvec)	(intvec+0x10U)

/*
 * Interrupt enable
 *	Enable the interrupt specified by ¡®dintno.'
 */
IMPORT void EnableInt( UINT dintno );

/*
 * Interrupt disable
 *	Disable the interrupt specified by 'dintno.'
 */
IMPORT void DisableInt( UINT dintno );

/*
 * Clear interrupt request
 *	Clear the interrupt request specified by 'dintno.'
*/
IMPORT void ClearInt( UINT dintno );

/*
 * Check for existence of interrupt request
 *	Check whether there is an interrupt request specified by 'dintno.'
 *	If there is an interrupt request, return TRUE (except 0).
 */
IMPORT BOOL CheckInt( UINT dintno );

/*
 * Issue EOI(End Of Interrupt)
 */
IMPORT void EndOfInt( UINT dintno );


/* ------------------------------------------------------------------------ */

/*
 * I/O port access
 *	Only memory mapped I/O for Arm
 */
Inline void out_w( UW port, UW data )
{
	*(_UW*)port = data;
}
Inline void out_h( UW port, UH data )
{
	*(_UH*)port = data;
}
Inline void out_b( UW port, UB data )
{
	*(_UB*)port = data;
}

Inline UW in_w( UW port )
{
	return *(_UW*)port;
}
Inline UH in_h( UW port )
{
	return *(_UH*)port;
}
Inline UB in_b( UW port )
{
	return *(_UB*)port;
}

#ifdef __cplusplus
}
#endif
#endif /* __TK_SYSLIB_DEPEND_H__ */
