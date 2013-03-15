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
 *    CPU:        AT91SAM3S4C
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/02/11-2012/09/23
 *	 Author	        : WangShb-wangxd
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified
/*
 *    Function Name : sio_init
 *    Create Date   : 2011/02/11-2012/09/23
 *    Author        : wangshb-wangxd
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* set to peripheral mode for UART transmit/receive */
	ldr     r1, =PIOA_BASE
	ldr     r2, =(0x01 << 9 | 0x01 << 10)
	str     r2, [r1, #PIO_PDR]

	/* UART clock enable */
	ldr     r1, =PMC_BASE
 	ldr     r2, =(0x01 << PI_UART0 )
 	str     r2, [r1, #PMC_PCER]

	/* Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit */
	ldr     r0, =UART0_BASE
	mov     r2, #0xC
	str     r2, [r0, #UART_CR]

    ldr     r2, =0xFFFFFFFF
	str     r2, [r0, #UART_IDR]

    mov     r2, #0x22    /* CD = MCLK/(baud*16) = 34.00(115200bps)   MCLK=64MHz */
	str     r2, [r0, #UART_BRGR]

    ldr     r2, =0x0800
	str     r2, [r0, #UART_MR]

    /* Disable DMA channel */
	ldr     r2, =0x200
	mov     r1, #0x2
	orr     r2, r2, r1
	ldr     r3, =PERIPH_PTCR
	str     r2, [r0, r3]

    /* Enable receiver and transmitter */
    mov     r2, #0x50
	str     r2, [r0, #UART_CR]

	bx	    lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/02/11-2012/09/23
 *    Author        : wangshb-wangxd
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
 	.text
 	.global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
    /* Wait for the transmitter to be ready while  */
wait_tx_ready:
	ldr     r2, =UART0_BASE
	ldr     r3, [r2, #UART_CSR]
	ldr     r1, =(0x1<<9)
	tst     r3, r1
	beq     wait_tx_ready

    /* Send character */
    ldrb     r0, [r0]          /* just get a character,not a word */
    strb     r0, [r2,#UART_THR]

wait_tx_end:
	ldr     r3, [r2, #UART_CSR]
	ldr     r1, =(0x1<<9)
	tst     r3, r1
	beq     wait_tx_end

	bx	    lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2011/02/11-2012/09/23
 *    Author        : wangshb-wangxd
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
 	.text
 	.global Csym(sio_recv_frame)
	.type	Csym(sio_recv_frame),function
Csym(sio_recv_frame):
    /* Wait for the receiver to be ready while */
	ldr     r2, =UART0_BASE
wait_rx_ready:
	ldr     r3, [r2, #UART_CSR]
	mov     r1, #0x1<<0
	tst     r3, r1
	beq     wait_rx_ready

	ldrb    r3, [r2, #UART_RHR]
	strb    r3, [r0]

	bx	    lr

	.end

