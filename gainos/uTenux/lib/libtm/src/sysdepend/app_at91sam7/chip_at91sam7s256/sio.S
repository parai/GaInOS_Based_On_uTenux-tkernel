/*
 *------------------------------------------------------------------------------
 *    Libtm
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
 *    CPU:        AT91SAM7
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2009/7/27-2012/9/30
 *	 Author	        : WangShb-wangxd
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2009/7/27-2012/9/30
 *    Author        : wangshb
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* set to peripheral mode for USART0 transmit/receive */
    ldr     r1, =PIOA_BASE
	mov     r2, #(0x01 << 5 | 0x01 << 6)
	str     r2, [r1, #PIO_PDR]

	/* USART0 clock enable */
	ldr     r1, =PMC_BASE
	mov     r2, #(0x01 << US0IRQ)
	str     r2, [r1, #PMC_PCER]

	/* Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit */
	ldr     r0, =USART0_BASE
	mov     r2, #0x08c0
	str     r2, [r0, #US_MR]
	mov     r2, #0x1a /* CD = MCLK/(baud*16) = 26.00(115200bps) */
	str     r2, [r0, #US_BRGR]

	mov     r2, #0x100
	orr     r2, #0x1
	str     r2, [r0, #PERIPH_PTCR]

	mov     r2, #0x10c
	str     r2, [r0, #US_CR]

    bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2009/7/27-2012/9/24
 *    Author        : wangshb
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
	.text
	.global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
	ldr     r2, =USART0_BASE

	str     r0, [r2, #PERIPH_TPR]
	str     r1, [r2, #PERIPH_TCR]

	mov     r3, #(1 << 6)
	str     r3, [r2, #US_CR]

wait_tx_end:
	ldr     r3, [r2, #US_CSR]
	tst     r3, #(1 << 4)
	beq     wait_tx_end   /* if ENDTX == 0 */

    bx      lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2009/7/27-2012/9/24
 *    Author        : wangshb
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
	.text
	.global Csym(sio_recv_frame)
	.type	Csym(sio_recv_frame),function
Csym(sio_recv_frame):
	ldr     r2, =USART0_BASE

	str     r0, [r2, #PERIPH_RPR]
	str     r1, [r2, #PERIPH_RCR]

	mov     r3, #(1 << 4)
	str     r3, [r2, #US_CR]

wait_rx_end:
	ldr     r3, [r2, #US_CSR]
	tst     r3, #(1 << 3)
	beq     wait_rx_end   /* if ENDRX == 0 */

    bx      lr

	.end
