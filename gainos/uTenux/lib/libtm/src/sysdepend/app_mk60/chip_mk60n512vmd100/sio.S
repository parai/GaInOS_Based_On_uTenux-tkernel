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
 *    CPU:        MK60N512VMD100
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2012/7/20-2012/09/17
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2012/07/24-2012/09/17
 *    Author        : Zhangzl-Zhangzl
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
    /* Enable port A/B/C/D/E */
	ldr     r0, =SIM_BASE
	ldr     r1, =0x3e00
	ldr     r2, [r0, #SIM_SCGC5]
	orr     r2, r1
	str     r2, [r0, #SIM_SCGC5]

    /* Enable UART3 clock */
	ldr     r0, =SIM_BASE
    ldr     r1, =SIM_SCGC4_UART3_MASK
    ldr     r2, [r0, #SIM_SCGC4]
    orr     r2, r1
    str     r2, [r0, #SIM_SCGC4]
    /* Enable PTC17/16 pin UART3 TXD/RXD function */
  	ldr     r0, =PORTC_BASE
  	ldr     r1, =((0x3<<PORT_PCR_MUX_SHIFT)&PORT_PCR_MUX_MASK)
  	str     r1, [r0, #PORT_PCR17]
  	str     r1, [r0, #PORT_PCR16]



	/* Disable UART */
	ldr     r0, =UART3_BASE
	ldr     r1, =(~(UART_C2_TE_MASK | UART_C2_RE_MASK))
	ldrb    r2, [r0, #UART_C2]
	and     r2, r1
	strb    r2, [r0, #UART_C2]

	/* 8bit, non-parity, 1 stop bit */
	ldr     r0, =UART3_BASE
	ldr     r1, =0x0
	strb    r1, [r0,#UART_C1]

	/* 115200bps Calculate baud setting */
	ldr     r0, =UART3_BASE
	ldr     r1, =0x1a
	ldrb    r2, [r0,#UART_BDH]
	ldr     r3, =(~UART_BDH_SBR)
	and     r2, r3    /* Save off the current value of the UART3_BDH except for the SBR */

	ldr     r0, =UART3_BASE
	ldr     r4, =0x1a
	ldr     r6, =0x1f00
	and     r4, r6
	lsr     r4, #0x08
	lsl     r4, #UART_BDH_SBR_SHIFT
	ldr     r6, =UART_BDH_SBR_MASK
	and     r4, r6
    orr     r2, r4
    strb    r2, [r0,#UART_BDH]

    ldr     r0, =UART3_BASE
    ldr     r2, =UART_BDL_SBR_MASK
    ldr     r3, =0x1a
    and     r3, r2
    strb    r3, [r0, #UART_BDL]

    /* brfa=0x1 */
    ldr     r0, =UART3_BASE
	ldr     r2, =0x1
	ldrb    r3, [r0,#UART_C4]
	ldr     r4, =(~UART_C4_BRFA)
	and     r3, r4

	ldr     r0, =UART3_BASE
	ldr     r5, =((0x1<<UART_C4_BRFA_SHIFT) & UART_C4_BRFA_MASK)
	orr     r3, r5
	strb    r3, [r0,#UART_C4]

    /* Enable receiver and transmitter */
    ldr     r0, =UART3_BASE
	ldr     r1, =(UART_C2_TE_MASK | UART_C2_RE_MASK)
	ldrb    r2, [r0, #UART_C2]
	orr     r2, r1
	strb    r2, [r0, #UART_C2]

	bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2012/07/24-2012/09/17
 *    Author        : Zhangzl-Zhangzl
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
 	.text
	.global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
    /* Wait for the transmitter to be ready while  */
    ldr     r2, =UART3_BASE
wait_tx_ready:
	ldrb    r3, [r2, #UART_S1]
	ldr     r1, =UART_S1_TDRE_MASK
	tst     r3, r1
	beq     wait_tx_ready

	/* Send character */
    ldrb    r0, [r0]          /* just get a character,not a word */
    strb    r0, [r2,#UART_D]

wait_tx_end:
    ldrb    r3, [r2, #UART_S1]
    ldr     r1, =UART_S1_TC_MASK
    tst     r3, r1
    beq     wait_tx_end

	bx      lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2012/07/24-2012/09/17
 *    Author        : Zhangzl-Zhangzl
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
 	.text
	.global Csym(sio_recv_frame)
	.type	Csym(sio_recv_frame),function
Csym(sio_recv_frame):
    /* Wait for the receiver to be ready while */
    ldr     r2, =UART3_BASE
wait_rx_ready:
    ldrb    r3, [r2, #UART_S1]
    ldr     r1, =UART_S1_RDRF_MASK
    tst     r3, r1
    beq     wait_rx_ready

    ldrb    r3, [r2, #UART_D]
    strb    r3, [r0]

	bx      lr

	.end

