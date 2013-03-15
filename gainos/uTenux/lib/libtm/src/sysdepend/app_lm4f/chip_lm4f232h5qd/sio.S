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
 *    CPU:        LM4F232H5QD
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/02/11-2012/09/24
 *	 Author	        : Dengjk-Dengjk
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

 .syntax unified
/*
 *    Function Name : sio_init
 *    Create Date   : 2011/02/11-2012/9/24
 *    Author        : wangshb-Dengjk
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):

	/* PORTA clock enable */
	ldr     r0, =SYSCTL_BASE
    ldr     r1, =SYSCTL_RCGC2_GPIOA
    ldr     r3, =SYSCTL_O_RCGC2
    ldr     r2, [r0, r3]
    orr     r2, r1
    str     r2, [r0, r3]

	/* UART0 clock enable */
	ldr     r0, =SYSCTL_BASE
    ldr     r1, =SYSCTL_RCGC1_UART0
    ldr     r3, =SYSCTL_O_RCGC1
    ldr     r2, [r0, r3]
    orr     r2, r1
    str     r2, [r0, r3]

    /* set to PA0/PA1 to UART0 peripheral mode  */

	/* Unlock GPIO CR */
	ldr     r0, =GPIO_PORTA_BASE
	ldr     r1, =GPIO_O_LOCK
	ldr     r2, =GPIO_LOCK_UL
	str     r2, [r0, r1]

    /* Let GPIO CR for PA0/PA1 Change */
    ldr     r1, =GPIO_O_CR
    ldr     r3, =(0x01 << 0 | 0x01 << 1)
	ldr     r2, [r0, r1]
	orr     r2,	r3
	str     r2, [r0, r1]

    /* Set PA0/PA1 as Peripheral */
    ldr     r1, =GPIO_O_AFSEL
    ldr     r3, =(0x01 << 0 | 0x01 << 1)
	ldr     r2, [r0, r1]
	orr     r2,	r3
	str     r2, [r0, r1]

    /* Set PA0/PA1 as UART0 */
    ldr     r1, =GPIO_O_PCTL
    ldr     r2, =(GPIO_PCTL_PA0_M|GPIO_PCTL_PA1_M)
    mvn     r3, r2
	ldr     r2, [r0, r1]
	and     r2,	r3
	mov     r3, #(GPIO_PCTL_PA0_U0RX|GPIO_PCTL_PA1_U0TX)
	orr     r2, r3
	str     r2, [r0, r1]

    /* Set PA0/PA1 as digital */
    ldr     r1, =GPIO_O_DEN
    ldr     r3, =(0x01 << 0 | 0x01 << 1)
	ldr     r2, [r0, r1]
	orr     r2,	r3
	str     r2, [r0, r1]

    /* Set PA0/PA1 as no pull up */
    ldr     r1, =GPIO_O_PUR
    ldr     r2, =(0x01 << 0 | 0x01 << 1)
    mvn     r3, r2
	ldr     r2, [r0, r1]
	and     r2,	r3
	str     r2, [r0, r1]

    /* Set PA0/PA1 as no pull down */
    ldr     r1, =GPIO_O_PDR
    ldr     r2, =(0x01 << 0 | 0x01 << 1)
    mvn     r3, r2
	ldr     r2, [r0, r1]
	and     r2,	r3
	str     r2, [r0, r1]

    /* Disable change GPIO CR for PA0/PA1  */
    ldr     r1, =GPIO_O_CR
    ldr     r2, =(0x01 << 0 | 0x01 << 1)
    mvn     r3, r2
	ldr     r2, [r0, r1]
	and     r2,	r3
	str     r2, [r0, r1]

    /* Lock GPIO CR */
    ldr     r1, =GPIO_O_LOCK
	ldr     r2, =GPIO_LOCK_M
	str     r2, [r0, r1]

	/* Disable uart  and TX/RX */
	ldr     r0, =UART0_BASE
	ldr     r2, [r0, #UART_O_CTL]
	ldr     r1, =(~(UART_CTL_UARTEN|UART_CTL_RXE|UART_CTL_TXE))
	and     r2, r1
	str     r2, [r0, #UART_O_CTL]

	/* Disable uart interrupt   */
    ldr     r2, =UART_IM_ALLIM
    mvn     r1, r2
	ldr     r2, [r0, #UART_O_IM]
	and     r2, r1
	str     r2, [r0, #UART_O_IM]

    /* Disable DMA channel      */
    ldr     r2, =(UART_DMACTL_RXDMAE|UART_DMACTL_TXDMAE)
    mvn     r1, r2
	ldr     r2, [r0, #UART_O_DMACTL]
	and     r2, r1
	str     r2, [r0, #UART_O_DMACTL]

	/* Set 8bit, non-parity, 1 stop bit, no FIFO */
    ldr     r2, =UART_LCRH_WLEN_8
	str     r2, [r0, #UART_O_LCRH]

    /* Set 115200bps,BRD = BRDI + BRDF = UARTSysClk / (ClkDiv * ²¨ÌØÂÊ)*/
    mov     r2, #0x2b
	str     r2, [r0, #UART_O_IBRD]
    mov     r2, #0x1a
	str     r2, [r0, #UART_O_FBRD]

    /* Disable CTS/RTS,and set 1/16   */
	ldr     r2, [r0, #UART_O_CTL]
	ldr     r1, =(~(UART_CTL_CTSEN|UART_CTL_RTSEN|UART_CTL_HSE))
	and     r2, r1
	str     r2, [r0, #UART_O_CTL]

    /* Enable receive and transmit  */
	ldr     r2, [r0, #UART_O_CTL]
	ldr     r1, =(UART_CTL_RXE|UART_CTL_TXE)
	orr     r2, r1
	str     r2, [r0, #UART_O_CTL]

    /* Enable uart   */
	ldr     r2, [r0, #UART_O_CTL]
	mov     r1, #UART_CTL_UARTEN
	orr     r2, r1
	str     r2, [r0, #UART_O_CTL]

	bx		 lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2012/08/01-2012/09/24
 *    Author        : Dengjk-Dengjk
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
	ldr     r3, [r2, #UART_O_FR]
	ldr     r1, =UART_FR_TXFE
	tst     r3, r1
	beq     wait_tx_ready

    // Send character
    ldrb     r0, [r0]          /*just get a character,not a word */
    strb     r0, [r2,#UART_O_DR]

wait_tx_end:
	ldr     r1, [r2, #UART_O_RSR]
	ldr     r3, [r2, #UART_O_FR]
	ldr     r1, =UART_FR_TXFE
	tst     r3, r1
	beq     wait_tx_end

	bx 		lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2012/08/01-2012/09/24
 *    Author        : Dengjk-Dengjk
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
	ldr     r3, [r2, #UART_O_FR]
	mov     r1, #UART_FR_RXFF
	tst     r3, r1
	beq     wait_rx_ready

	ldrb    r3, [r2, #UART_O_DR]
	strb    r3, [r0]

	bx		 lr
