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
 *    CPU:        LPC1788
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/10/10-2012/09/24
 *	 Author	        : wangxd-wangxd
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2011/10/10-2012/09/24
 *    Author        : wangxd-wangxd
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* set to peripheral mode for UART0 transmit/receive */
    ldr     r1, =IOCONP0_BASE
    ldr     r2, [r1, #IOCONP_02]
    ldr     r3, =(~0x7)
    and     r2, r3
    ldr     r3, =0x1
    orr     r2, r3
    str     r2, [r1, #IOCONP_02]

    ldr     r1, =IOCONP0_BASE
    ldr     r2, [r1, #IOCONP_03]
    ldr     r3, =(~0x7)
    and     r2, r3
    ldr     r3, =0x1
    orr     r2, r3
    str     r2, [r1, #IOCONP_03]

	/* UART0 clock enable */
 	ldr     r1, =CPC_BASE
 	ldr     r0, =CPC_PCONP
 	ldr     r2, [r1, r0]
 	ldr     r3, =(0x1 << 3)
 	orr     r2, r3
    str     r2, [r1, r0]

	/* 8bit, non-parity, 1 stop bit  */
	ldr     r0, =UART0_BASE
    mov     r2, #0x83
	str     r2, [r0, #UART_LCR]

    /* 115200 baud rate at 60MHz PCLK */
    mov     r2, #25
	str     r2, [r0, #UART_DLL]

    /* FR=1.556  DIVADDVAL=3  MULVAL=10 PCLK=60MHz*/
    ldr     r2, =0xa3
	str     r2, [r0, #UART_FDR]

    /* High divisor latch = 0          */
    ldr     r2, =0x0
	str     r2, [r0, #UART_DLM]

    /* DLAB = 0                        */
    mov     r2, #0x3
	str     r2, [r0, #UART_LCR]

    bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/10/10-2012/09/24
 *    Author        : wangxd-wangxd
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
	ldr     r3, [r2, #UART_LSR]
	ldr     r1, =(0x1<<5)
	tst     r3, r1
	beq     wait_tx_ready

    /* Send character£¬just a character,not a word */
    ldrb     r0, [r0]
    strb     r0, [r2,#UART_THR]

wait_tx_end:
	ldrb    r3, [r2, #UART_LSR]
	ldr     r1, =(0x1<<5)
	tst     r3, r1
	beq     wait_tx_end

    bx      lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2011/10/10-2012/09/24
 *    Author        : wangxd-wangxd
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
	ldrb    r3, [r2, #UART_LSR]
	mov     r1, #0x1
	tst     r3, r1
	beq     wait_rx_ready

	ldrb    r3, [r2, #UART_RBR]
	strb    r3, [r0]

    bx      lr

	.end

