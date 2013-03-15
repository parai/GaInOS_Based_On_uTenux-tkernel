/*
 *------------------------------------------------------------------------------
 *    Libtk
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
 *    CPU:        ARM7&9
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : int.c
 *	 Create Date    : 2009/7/27-2012/9/21
 *	 Author	        : WangShb
 *	 Description    : Nested Vectored Interrupt controller.
 *-------------------------------------------------------------------------------
 */

#include <basic.h>
#include <tk/syslib.h>
#include <tk/sysdef.h>

/*
 * Set interrupt mode 
 *	
 *	Sets the interrupt specified in 'intvec' to the mode specified
 *	in 'mode'.
 *	FIQ and IRQ interrupt can be specified.
 *	Interrupt controller level register and polarity register are set.
 *
 *	mode := (IM_LEVEL || IM_EDGE) | (IM_HI || IM_LOW)
 */
EXPORT void SetIntMode( INTVEC intvec, UINT mode )
{
	UINT	imask;
	_UW	*reg = (_UW*)(AIC_BASE + intvec*4); /* AIC_SMRn */

	DI(imask);

	/* Keep interrupt controller level register
	 * and modify polarity register */
	*reg = (mode << 5) | (*reg & 0x07U);

	EI(imask);
}

/*
 * Enable interrupt 
 *	Enables the interrupt specified in intvec.
 *	FIQ and IRQ interrupt can be specified. 
 */
EXPORT void EnableInt( INTVEC intvec )
{
	UINT	imask;

	DI(imask);

	*(_UW*)(AIC_BASE | AIC_IECR) = (0x01U << intvec);

	EI(imask);
}

/*
 * Disable interrupt 
 *	Disables the interrupt specified in intvec.
 *	FIQ and IRQ interrupt can be specified.
 */
EXPORT void DisableInt( INTVEC intvec )
{
	UINT	imask;

	DI(imask);

	*(_UW*)(AIC_BASE | AIC_IDCR) = (0x01U << intvec);

	EI(imask);
}

/*
 * Clear interrupt request 
 *	Clears the intvec interrupt request.
 *	Valid only for edge trigger.
 *	For edge trigger, the interrupt must be cleared with an
 *	interrupt handler.
 *	FIQ and IRQ interrupt can be specified.
 */
EXPORT void ClearInt( INTVEC intvec )
{
	*(_UW*)(AIC_BASE | AIC_ICCR) = (0x01U << intvec);
}

/*
 * Check for interrupt requests 
 *	Checks for intvec interrupt  requests.
 *	If an interrupt request is found, returns TRUE (other than 0).
 *	FIQ and IRQ interrupt can be specified.
 */
EXPORT BOOL CheckInt( INTVEC intvec )
{
	if (intvec < 32) {
		return (BOOL)((*(_UW*)(AIC_BASE | AIC_IPR) & (0x01U << intvec)) != 0);
	}

	return FALSE;
}

/*
 * Notify end of interrupt
 */
EXPORT void EndOfInt( INTVEC intvec )
{
	/* write anything to notify */
	*(_UW*)(AIC_BASE | AIC_EOICR) = 0x01;
}
