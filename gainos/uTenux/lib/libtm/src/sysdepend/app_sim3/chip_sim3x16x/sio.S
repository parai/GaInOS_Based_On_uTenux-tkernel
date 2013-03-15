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
 *    CPU:        SIM3U167
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/02/11-2012/11/5
 *	 Author	        : dengjk-wangxd
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified
/*
 *    Function Name : sio_init
 *    Create Date   : 2011/02/11-2012/11/05
 *    Author        : wangshb-wangxd
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
   	/* enable uart0 clock */
	ldr		r0, =CLKCTRL0_BASE
	ldr		r1, =(0x1<<4)
	str		r1, [r0,#CLKCTRL0_APBCLKG0_SET]

    /* enable port bank */
    ldr     r0, =CLKCTRL0_BASE
    ldr     r1, =(0x1<<1)
    str     r1, [r0, #CLKCTRL0_APBCLKG0_SET]

    /* config uart0 pins */
	ldr 	r0, =PBSTD1_BASE
	ldr 	r1, =0x8
	str 	r1, [r0,#PBSTD_PBOUTMD_SET]
	str 	r1, [r0,#PBSTD_PBMDSEL_SET]

 	/* enable crossbar 0, drive uart0 */
	ldr	 	r0, =PBCFG0_BASE
	ldr 	r1, =0x80000000
	str 	r1, [r0,#PBCFG0_XBAR0H_SET]

	/* config TX:PB1.12  RX:PB1.13 */
	ldr 	r0, =PBSTD1_BASE
	ldr 	r1, =0x1000
	str 	r1, [r0,#PBSTD_PBOUTMD_SET]
	str 	r1, [r0,#PBSTD_PBMDSEL_SET]

	ldr 	r1, =0x00002000
	str 	r1, [r0,#PBSTD_PBOUTMD_CLR]
	str 	r1, [r0,#PBSTD_PB_SET]
	str 	r1, [r0,#PBSTD_PBMDSEL_SET]

	ldr 	r0, =PBSTD0_BASE
	ldr 	r1, =0xffff
	str 	r1, [r0,#PBSTD_PBSKIPEN]

	ldr 	r0, =PBSTD1_BASE
	ldr 	r1, =0xfff
	str 	r1, [r0,#PBSTD_PBSKIPEN]

	ldr 	r0, =PBCFG0_BASE
	ldr 	r1, =0x1
	str 	r1, [r0,#PBCFG0_XBAR0H_SET]

	/* init uart0 full-duplex, Frequency AHB=2*APB */
	ldr		r0, =UART0_BASE
	ldr		r1, =0x08000000
	str		r1, [r0,#UART_MODE_CLR]

    /* baudrate 115200 */
	ldr		r1, =0x00ac00ac
	str		r1, [r0,#UART_BAUDRATE]

   /* 8-bit, 1stop, no-parity */
	ldr		r1, =0x030d030d
	str		r1, [r0,#UART_CONFIG_SET]

	/*disable signal inver*/
	ldr		r1, =0x4000
	str		r1, [r0,#UART_CONFIG_CLR]

	/*enable tx and rx*/
	ldr		r3, =(0x1<<31) | (0x1<<15)
	str		r3, [r0,#UART_CONTROL_SET]

	bx	    lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/02/11-2012/09/26
 *    Author        : wangshb-Dengjk
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
 	.text
 	.global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
wait_tx_ready:
   /* Wait for the transmitter to be ready while*/
 	ldr     r2, =UART0_BASE
	ldr     r3, [r2, #UART_FIFOCN]
	ldr     r2, =0x00070000
	and     r3, r2
	lsr		r3, #16
	cmp	 	r3, #4
	bge     wait_tx_ready

   /* Send character*/
    ldr     r2, =UART0_BASE
    ldrb    r1, [r0]
    strb    r1, [r2,#UART_DATA]

   	bx 	   lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2011/02/11-2012/09/26
 *    Author        : wangshb-Dengjk
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
    ldr     r3, [r2, #UART_FIFOCN]
	tst     r3, #0x7
    beq     wait_rx_ready

	ldrb    r3, [r2, #UART_DATA]
	strb    r3, [r0]

    bx	   lr

   .end

