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
 *    CPU:        MB9BF506R
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2012/7/19-2012/09/24
 *	 Author	        : WangShb-Zhangzl
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

     .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2011/02/11-2012/09/24
 *    Author        : wangshb-Zhangzl
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* set to peripheral mode and MFS 0 for UART0 transmit/receive */
	ldr     r1, =(IOP_BASE+IOP_PFR2)
	ldr     r2, [r1]
	ldr     r3, =0x0006
	orr     r2, r3
	str     r2, [r1]

    ldr     r1, =(IOP_BASE+IOP_EPFR07)
	ldr     r2, [r1]
	ldr     r3, =0x0040
	orr     r2, r3
	str     r2, [r1]

	/* Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit */
	ldr     r0, =UART0_BASE
    /* Set Asynchronous Mode, 1 stop bit,LSB                      */
    mov     r2, #0x01
	strb    r2, [r0, #UART_SMR]

    /* Disable receiver and transmitter                           */
    mov     r2, #0x00
	strb    r2, [r0, #UART_SCR]

    ldr     r2, =0x15a              /* V = CLK/baud - 1= 346.00   */
	strh    r2, [r0, #UART_BGR]

    ldr     r2, =0x00               /* non-parity, 8bit           */
	strh    r2, [r0, #UART_ESCR]

    /* Enable receiver and transmitter                 */
    mov     r2, #0x03
	strb    r2, [r0, #UART_SCR]

	bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/02/11-2012/09/24
 *    Author        : wangshb-zhangzl
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
	ldrb    r3, [r2, #UART_SSR]
	ldr     r1, =(0x1<<1)
	tst     r3, r1
	beq     wait_tx_ready

    /* Send character£¬just a character,not a word */
    ldrb     r0, [r0]
    strb     r0, [r2,#UART_TDR]

wait_tx_end:
	ldrb    r3, [r2, #UART_SSR]
	ldr     r1, =(0x1<<1)
	tst     r3, r1
	beq     wait_tx_end

	bx      lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2011/02/11-2012/09/24
 *    Author        : wangshb-zhangzl
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
	ldrb    r3, [r2, #UART_SSR]
	mov     r1, #0x1<<2
	tst     r3, r1
	beq     wait_rx_ready

	ldrb    r3, [r2, #UART_RDR]
	strb    r3, [r0]

	bx      lr

	.end

