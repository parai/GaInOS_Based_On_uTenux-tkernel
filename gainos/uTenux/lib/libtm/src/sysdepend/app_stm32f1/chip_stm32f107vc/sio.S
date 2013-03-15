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
 *    CPU:        STM32F107VC
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2012/7/9-2013/1/24
 *	 Author	        : WangShb-wangshb
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2011/02/11-2013/01/24
 *    Author        : wangshb-wangxd
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* GPIOD clock enable */
	ldr     r0, =RCC_BASE
    mov     r1, #( 0x01<<RCC_APB2ENR_IOPDEN_SHIFT )
    ldr     r2, [r0, #RCC_APB2ENR]
    orr     r2, r1
    str     r2, [r0, #RCC_APB2ENR]

	/* UART2 clock enable */
    ldr     r1, =( 0x01<<RCC_APB1ENR_UART2EN_SHIFT )
    ldr     r2, [r0, #RCC_APB1ENR]
    orr     r2, r1
    str     r2, [r0, #RCC_APB1ENR]

	/* set PD5/PD6 to Alternate function for UART2 transmit/receive */
	ldr     r0, =GPIOD_BASE
    ldr     r1, =~( ((GPIO_CR_CNF_MASK<<2)|GPIO_CR_MODE_MASK )<<GPIO_CRL_SHIFT(5) )
	ldr     r2, [r0, #GPIO_CRL]
	and     r2, r1
	ldr     r1, =( ((GPIO_CR_CNF_IN_PULLUPDOWN<<2)| GPIO_CR_MODE_OUT_50M )<< GPIO_CRL_SHIFT(5) )
    orr     r2, r1
	str     r2, [r0, #GPIO_CRL]

	ldr     r1, =~( ((GPIO_CR_CNF_MASK<<2)| GPIO_CR_MODE_MASK )<< GPIO_CRL_SHIFT(6) )
	ldr     r2, [r0, #GPIO_CRL]
	and     r2, r1
	ldr     r1, =( ((GPIO_CR_CNF_IN_FLOATING<<2)| GPIO_CR_MODE_IN )<< GPIO_CRL_SHIFT(6) )
    orr     r2, r1
	str     r2, [r0, #GPIO_CRL]

	/* Disable USART and TX and RX */
	ldr     r0, =USART2_BASE
	ldr     r1, =0xFFFFDFF3
	ldr     r2, [r0, #USART_CR1]
	and     r2, r1
	str     r2, [r0, #USART_CR1]

    /* Clear STOP bit,CLKEN,CPOL,CPHA */
	ldr     r1, =0xFFFF8060
	ldr     r2, [r0, #USART_CR2]
	and     r2, r1
	str     r2, [r0, #USART_CR2]

    /* Set 8bit,non parity,no interupt */
	ldr     r1, =0xFFFFE80F
	ldr     r2, [r0, #USART_CR1]
	and     r2, r1
	str     r2, [r0, #USART_CR1]

    /* Disable CTS and DMA */
	ldr     r1, =0xFFFFF800
	ldr     r2, [r0, #USART_CR3]
	and     r2, r1
	str     r2, [r0, #USART_CR3]

	/* Set baud=115200bps */
    ldr     r2, =0x0271
	str     r2, [r0, #USART_BRR]

    /* Enable receiver and transmitter and USART */
	ldr     r1, =0x00000200C
	ldr     r2, [r0, #USART_CR1]
	orr     r2, r1
	str     r2, [r0, #USART_CR1]

    bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/02/11-2013/01/24
 *    Author        : wangshb-wangshb
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
 	.text
	.global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
    /* Wait for the transmitter to be ready while */
	ldr     r2, =USART2_BASE
wait_tx_ready:
	ldr     r3, [r2, #USART_SR]
	ldr     r1, =(0x1<<USART_SR_TXE_SHIFT)
	tst     r3, r1
	beq     wait_tx_ready

    /* Send character */
    ldrb     r0, [r0]          /* just get a character,not a word */
    strb     r0, [r2,#USART_DR]

wait_tx_end:
	ldr     r3, [r2, #USART_SR]
	ldr     r1, =(0x1<<USART_SR_TXE_SHIFT)
	tst     r3, r1
	beq     wait_tx_end

    bx      lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2011/02/11-2013/01/24
 *    Author        : wangshb-wangshb
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
 	.text
	.global Csym(sio_recv_frame)
	.type	Csym(sio_recv_frame),function
Csym(sio_recv_frame):
    /* Wait for the receiver to be ready while */
	ldr     r2, =USART2_BASE
wait_rx_ready:
	ldr     r3, [r2, #USART_SR]
	mov     r1, #0x1<<USART_SR_RXNE_SHIFT
	tst     r3, r1
	beq     wait_rx_ready

	ldrb    r3, [r2, #USART_DR]
	strb    r3, [r0]

    bx      lr

	.end


