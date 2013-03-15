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
 *    CPU:        STM32F407IG
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/11/29-2012/9/8
 *	 Author	        : WangShb-WangShb
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2011/11/29-2012/10/11
 *    Author        : wangshb-wangxd
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):
	/* GPIOC clock enable */
	ldr     r0, =RCC_BASE
    mov     r1, #( 0x01<<RCC_AHB1ENR_GPIOCEN_SHIFT )
    ldr     r2, [r0, #RCC_AHB1ENR]
    orr     r2, r1
    str     r2, [r0, #RCC_AHB1ENR]

	/* USART3 clock enable */
    ldr     r1, =( 0x01<<RCC_APB1ENR_USART3EN_SHIFT )
    ldr     r2, [r0, #RCC_APB1ENR]
    orr     r2, r1
    str     r2, [r0, #RCC_APB1ENR]

	/* set PC10/PC11 to Alternate function for USART3 transmit/receive */
	ldr     r0, =GPIOC_BASE
    ldr     r1, =~( GPIO_MODER_MASK<<GPIO_MODER_SHIFT(10) )
	ldr     r2, [r0, #GPIO_MODER]
	and     r2, r1
	ldr     r1, =( GPIO_MODER_AF<<GPIO_MODER_SHIFT(10) )
    orr     r2, r1
	str     r2, [r0, #GPIO_MODER]

    ldr     r1, =~( GPIO_OTYPER_MASK<<GPIO_OTYPER_SHIFT(10) )
	ldr     r2, [r0, #GPIO_OTYPER]
	and     r2, r1
	str     r2, [r0, #GPIO_OTYPER]

    ldr     r1, =~( GPIO_PUPDR_MASK<<GPIO_PUPDR_SHIFT(10) )
	ldr     r2, [r0, #GPIO_PUPDR]
	and     r2, r1
	ldr     r1, =( GPIO_PUPDR_PULLUP<<GPIO_PUPDR_SHIFT(10) )
    orr     r2, r1
	str     r2, [r0, #GPIO_PUPDR]

    ldr     r1, =~( GPIO_OSPEEDR_MASK<<GPIO_OSPEEDR_SHIFT(10) )
	ldr     r2, [r0, #GPIO_OSPEEDR]
	and     r2, r1
	ldr     r1, =( GPIO_OSPEEDR_50M<<GPIO_OSPEEDR_SHIFT(10) )
    orr     r2, r1
	str     r2, [r0, #GPIO_OSPEEDR]

	ldr     r1, =~( GPIO_AFR_MASK<<GPIO_AFRH_SHIFT(10) )
	ldr     r2, [r0, #GPIO_AFRH]
	and     r2, r1
	ldr     r1, =( GPIO_AFR_AF7<<GPIO_AFRH_SHIFT(10) )
    orr     r2, r1
	str     r2, [r0, #GPIO_AFRH]

    ldr     r1, =~( GPIO_MODER_MASK<<GPIO_MODER_SHIFT(11) )
	ldr     r2, [r0, #GPIO_MODER]
	and     r2, r1
	ldr     r1, =( GPIO_MODER_AF<<GPIO_MODER_SHIFT(11) )
    orr     r2, r1
	str     r2, [r0, #GPIO_MODER]

    ldr     r1, =~( GPIO_PUPDR_MASK<<GPIO_PUPDR_SHIFT(11) )
	ldr     r2, [r0, #GPIO_PUPDR]
	and     r2, r1
	ldr     r1, =( GPIO_PUPDR_PULLUP<<GPIO_PUPDR_SHIFT(11) )
    orr     r2, r1
    str     r2, [r0, #GPIO_PUPDR]

    ldr     r1, =~( GPIO_OSPEEDR_MASK<<GPIO_OSPEEDR_SHIFT(11) )
	ldr     r2, [r0, #GPIO_OSPEEDR]
	and     r2, r1
	ldr     r1, =( GPIO_OSPEEDR_50M<<GPIO_OSPEEDR_SHIFT(11) )
    orr     r2, r1
	str     r2, [r0, #GPIO_OSPEEDR]

	ldr     r1, =~( GPIO_AFR_MASK<<GPIO_AFRH_SHIFT(11) )
	ldr     r2, [r0, #GPIO_AFRH]
	and     r2, r1
	ldr     r1, =( GPIO_AFR_AF7<<GPIO_AFRH_SHIFT(11) )
    orr     r2, r1
	str     r2, [r0, #GPIO_AFRH]

	/* Disable USART and TX and RX */
	ldr     r0, =USART3_BASE
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
    ldr     r2, =0x016C
	str     r2, [r0, #USART_BRR]

    /* Enable receiver and transmitter and USART */
	ldr     r1, =0x0000200C
	ldr     r2, [r0, #USART_CR1]
	orr     r2, r1
	str     r2, [r0, #USART_CR1]

    bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/11/29-2012/8/28
 *    Author        : wangshb
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
 	.text
	.global Csym(sio_send_frame)
	.type	Csym(sio_send_frame),function
Csym(sio_send_frame):
    /* Wait for the transmitter to be ready while */
	ldr     r2, =USART3_BASE
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
 *    Create Date   : 2011/11/29-2012/8/28
 *    Author        : wangshb
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
 	.text
	.global Csym(sio_recv_frame)
	.type	Csym(sio_recv_frame),function
Csym(sio_recv_frame):
    /* Wait for the receiver to be ready while */
	ldr     r2, =USART3_BASE
wait_rx_ready:
	ldr     r3, [r2, #USART_SR]
	mov     r1, #0x1<<USART_SR_RXNE_SHIFT
	tst     r3, r1
	beq     wait_rx_ready

	ldrb    r3, [r2, #USART_DR]
	strb    r3, [r0]

    bx      lr

	.end

