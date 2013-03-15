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
 *    CPU:        EFM32G890F128
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/02/11-2012/08/11
 *	 Author	        : wangxd-wangxd
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>
    .syntax unified
/*
 *    Function Name : sio_init
 *    Create Date   : 2012/07/18-2012/09/18
 *    Author        : wangxd-Dengjk
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* set to peripheral mode for UART0#1 transmit/receive */

	ldr   r0, =CMU_BASE
    ldr   r1, =CMU_LOCK_UNLOCKVALUE
    ldr   r2, =CMU_LOCK
    str   r1, [r0, r2]

    /* UART0/GPIO clock enable */
 	ldr   r1, =(0x1<<3 | 0x1<<12)
 	str   r1, [r0, #CMU_HFPERCLKEN0]

	ldr   r1, =CMU_LOCK_LOCKVALUE
	ldr   r2, =CMU_LOCK
	str   r1, [r0, r2]

    /* GPIO register unlock */
    ldr     r0, =GPIO_BASE
	ldr     r2, =GPIO_LOCK_UNLOCKVALUE
	ldr     r3, =GPIO_LOCK
	str     r2, [r0, r3]

    /* 6mA driver current */
    ldr     r1, =GPIO_PE_BASE
	ldr     r2, =0x00
    str     r2, [r1, #GPIO_CTRL]

    /* PE0 PUSHPULL model¡¢PE1 INPUT model */
	ldr     r2, =((0x01<<4) | (0x4<<0))
	str     r2, [r1, #GPIO_MODEL]

    /* GPIO register lock */
	ldr     r2, =GPIO_LOCK_LOCKVALUE
	ldr     r3, =GPIO_LOCK
	str     r2, [r0, r3]

    /* transmitter and receiver disable */
	ldr     r0, =UART0_BASE
	mov     r2, #0x0a
	str     r2, [r0, #UART_CMD]

    /* Asynchronous Mode, Oversample 16 */
	mov     r2, #0x0
	str     r2, [r0, #UART_CTRL]

    /* non-parity, one stop bit, 8 data bit */
	ldr     r2, =0x1005
	str     r2,[r0, #UART_FRAME]

    /* set bauds 115200bps */
	ldr     r2, =0x699
	str     r2, [r0, #UART_CLKDIV]

    /* diable Interrupt */
	mov     r2, #0x0
	str     r2, [r0, #UART_IEN]

    /* select UART location */
	ldr     r2, =0x10f
	str     r2, [r0, #UART_ROUTE]

    /* transmitter,receiver Enable,clear RX/TX enable */
	ldr     r2, =0x5
	str     r2, [r0, #UART_CMD]

uart0_cmd_delay:
	ldr     r1,[r0, #UART_STATUS]
	ldr     r2, =0x3
	tst     r1, r2
	beq     uart0_cmd_delay

	bx	    lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2012/07/18-2012/09/18
 *    Author        : wangxd-Dengjk
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
 	.text
    .global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
    /* Wait for the transmitter to be ready while */
wait_tx_ready:
	ldr     r2, =UART0_BASE
	ldr     r3, [r2, #UART_STATUS]
	ldr     r1, =(0x1<<6)
	tst     r3, r1
	beq     wait_tx_ready

    /* Send character£¬just a character,not a word */
    ldrb     r0, [r0]
    ldr      r5, =UART_TXDATA
    strb     r0, [r2,r5]

wait_tx_end:
	ldr     r3, [r2, #UART_STATUS]
	ldr     r1, =(0x1<<5)
	tst     r3, r1
	beq     wait_tx_end

	bx	    lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2012/07/18-2012/09/18
 *    Author        : wangxd-Dengjk
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
 	.text
 	.global Csym(sio_recv_frame)
	.type	Csym(sio_recv_frame),function
Csym(sio_recv_frame):
        /* Wait for the receiver to be ready */
	ldr     r2, =UART0_BASE
wait_rx_ready:
	ldrb    r3, [r2, #UART_STATUS]
	mov     r1, #(0x1<<7)
	tst     r3, r1
	beq     wait_rx_ready

	ldr     r1, =UART_RXDATA
	ldrb    r3, [r2, r1]
	strb    r3, [r0]

	bx	    lr

	.end

