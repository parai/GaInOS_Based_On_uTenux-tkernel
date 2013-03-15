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
 *    CPU:        AT91SAM7S256
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : syslib_depend.h
 *	 Create Date    : 2009/7/27-2012/9/21
 *	 Author	        : WangShb
 *	 Description    : micro T-Kernel Library(tk/AT91SAM7).
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
 *	'intsts' is the value of CPSR in CPU
 *	disint()  Set CPSR.I = 1 and F = 1 and return the original CPSR
 *		  to the return value.
 *	enaint()  Set CPSR.I,F = intsts.I,F. Do not change except
 *		  for CPSR.I,F.
 *		  Return the original CPSR to the return value.
 */
IMPORT UINT disint( void );
IMPORT UINT enaint( UINT intsts );
#define DI(intsts)	( (intsts) = disint() )
#define EI(intsts)	( enaint(intsts) )
#define isDI(intsts)	( ((intsts) & 0x00c0U) != 0 )

/*
 * Interrupt vector
 *	The interrupt vector is the index number of the vector table.
 */
typedef UINT	INTVEC;

/* Convert to interrupt definition number */
#define DINTNO(intvec)	(intvec)

/*
 * Interrupt mode setting
 *	Set the interrupt specified by 'intvec' to the mode specified
 *	by 'mode.'
 *	For FIQ IRQ, the interrupt controllers, Level register and
 *	Polarity register, are set.
 *
 *	For GPA GPB, the GPIO controllers, Interrupt Type register
 *	and Interrupt Polarity register, are set.
 *
 *	mode := (IM_LEVEL || IM_EDGE) | (IM_HI || IM_LOW)
 */
IMPORT void SetIntMode( INTVEC intvec, UINT mode );

#define IM_LEVEL	0	/* level trigger */
#define IM_EDGE		1	/* edge  trigger */
#define IM_HI		2	/* high level trigger/positive edge trigger */
#define IM_LOW		0	/* low  level trigger/negative edge trigger */

/*
 * Interrupt enable
 *	Enable the interrupt specified by 'intvec.'
 */
IMPORT void EnableInt( INTVEC intvec );

/*
 * Interrupt disable
 *	Disable the interrupt specified by 'intvec.'
 */
IMPORT void DisableInt( INTVEC intvec );

/*
 * Clear interrupt request
 *	Clear the interrupt request specified by 'intvec.'
 *	Available only for edge trigger.
 *	For edge trigger, need to clear the interrupt with
 *	interrupt handler.
 */
IMPORT void ClearInt( INTVEC intvec );

/*
 * Check for existence of interrupt request
 *	Check whether there is an interrupt request specified by 'intvec.'
 *	If there is an interrupt request, return TRUE (except 0).
 */
IMPORT BOOL CheckInt( INTVEC intvec );

/*
 * Issue EOI(End Of Interrupt)
 */
IMPORT void EndOfInt( INTVEC intvec );

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
