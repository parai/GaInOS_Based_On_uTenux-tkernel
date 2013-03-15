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
 *    CPU:        XMC4500F144K1024
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2012/9/6-2012/12/05
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>

    .syntax unified

/*
 *    Function Name : sio_init
 *    Create Date   : 2012/9/6-2012/09/20
 *    Author        : Zhangzl-Zhangzl
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
	.text
	.global Csym(sio_init)
	.type	Csym(sio_init),function
Csym(sio_init):

clr_prclr0_usic:
    ldr     r0, =SCU_BASE
    ldr     r1, =SCU_PRCLR0
    ldr     r2, [r0, r1]
    ldr     r3, =SCU_PRCLR0_USIC0RS
    orr     r2, r3
    str     r2, [r0, r1]

wait_clr_prclr0_usic:
    ldr     r0, =SCU_BASE
    ldr     r1, =SCU_PRSTAT0
    ldr     r2, [r0, r1]
    ldr     r3, =SCU_PRSTAT0_USIC0RS
    tst     r2, r3
    bne     wait_clr_prclr0_usic

	/* Enable USIC module. */
	ldr     r0, =USIC0_CH0_BASE
	ldr     r1, =USIC_KSCFG
	ldr     r2, =(USIC_KSCFG_MODEN | USIC_KSCFG_BPMODEN)
	str     r2, [r0, r1]

	ldr     r0, =USIC0_CH0_BASE
	ldr     r1, =USIC_CCR
	ldr     r2, =0x0
	str     r2, [r0, r1]

    /* Configuration of RX Pin 1.4. */
    ldr     r0, =USIC0_CH0_BASE
    ldr     r1, =USIC_DX0CR
    ldr     r2, =USIC_DX0CR_DSEL
    str     r2, [r0, r1]

	/* Configuration of TX Pin 1.5 ALT function 2 */
    ldr     r0, =P1_BASE
    ldr     r1, =P_IOCR4
    ldr     r2, [r0, r1]
    ldr     r3, =P_IOCR4_PC4
    orr     r2, r3
    str     r2, [r0, r1]

config_usic_divider:
    /* Configuration of usic channel fractional divider.
     * STEP=0x200£¨512£©,FD clock = PB clock/2 = 60MHz.
     */
    ldr     r0, =USIC0_CH0_BASE
    ldr     r1, =USIC_FDR
    ldr     r2, =(USIC_FDR_DM | USIC_FDR_STEP)
    str     r2, [r0, r1]

baud_rate_set:
    /* Select FD clock as PIN clock.
     * Baut rate 115200.PDIV = 0xf, PCTQ = 0x01, DCTQ = 0xf.
     */
    ldr     r0, =USIC0_CH0_BASE
    ldr     r1, =USIC_BRG
    ldr     r2, =(USIC_BRG_PCTQ | USIC_BRG_DCTQ | USIC_BRG_PDIV)
    ldr     r3, =(~USIC_BRG_CLKSEL)
    and     r2, r3
    str     r2, [r0, r1]

uart_init:
    /* Transmit/Receive LSB first is selected.
     * Transmission Mode (TRM) = 1.
     * Passive Data Level (PDL) = 1.
     * data 8 bit.
     */
    ldr     r0, =USIC0_CH0_BASE
    ldr     r1, =USIC_SCTR
    ldr     r2, =(USIC_SCTR_PDL|USIC_SCTR_TRM|USIC_SCTR_FLE|USIC_SCTR_WLE)
    str     r2, [r0, r1]

	ldr     r0, =USIC0_CH0_BASE
    ldr     r1, =USIC_TCSR
    ldr     r2, =(USIC_TCSR_TDSSM | USIC_TCSR_TDEN)
    str     r2, [r0, r1]

    /* One stop bit£¬receiver/transmitter status enable.*/
    ldr     r0, =USIC0_CH0_BASE
    ldr     r1, =USIC_PCR
    ldr     r2, =(USIC_PCR_SMD | USIC_PCR_SP)
    ldr     r3, =(USIC_PCR_RSTEN | USIC_PCR_TSTEN)
    orr     r2, r3
    str     r2, [r0, r1]

select_uart_mode:
	/* Select uart/ASC mode,disable party mode.*/
	ldr     r0, =USIC0_CH0_BASE
	ldr     r1, =USIC_CCR
	ldr     r2, =(USIC_CCR_UART_MODE|USIC_CCR_PM)
	str     r2, [r0, r1]

wait_uart_mode:
	ldr     r0, =USIC0_CH0_BASE
	ldr     r1, =USIC_CCFG
	ldr     r2, [r0, r1]
	ldr     r3, =USIC_CCFG_UART_MODE
	tst     r2, r3
	beq     wait_uart_mode

	bx      lr

/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2012/9/6-2012/10/11
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
    ldr     r2, =USIC0_CH0_BASE
wait_tx_ready:
	ldr     r3, =USIC_PSR
	ldr     r1, [r2, r3]
	ldr     r3, =USIC_PSR_BUSY
	tst     r1, r3
	bne     wait_tx_ready

    /* Send character */
    ldrb    r0, [r0]          /* just get a character,not a word */
    ldr     r3, =USIC_TBUF(0)
    strb    r0, [r2, r3]

wait_tx_end:
    ldr     r3, =USIC_PSR
	ldr     r1, [r2, r3]
	ldr     r3, =USIC_PSR_TFF
	tst     r1, r3
	beq     wait_tx_end

	bx      lr

/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2012/9/6-2012/12/05
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
	ldr     r2, =USIC0_CH0_BASE
wait_rx_ready:
	ldr     r3, =USIC_PSR
	ldr     r1, [r2, r3]
	ldr     r3, =USIC_PSR_RIF
	tst     r1, r3
	beq     wait_rx_psr_aif
    b       usic_psr_clr

wait_rx_psr_aif:
    ldr     r3, =USIC_PSR
	ldr     r1, [r2, r3]
	ldr     r3, =USIC_PSR_AIF
	tst     r1, r3
	beq     wait_rx_ready
    b       usic_psr_clr

usic_psr_clr:
	ldr     r2, =USIC0_CH0_BASE
	ldr     r1, =(USIC_PSCR_CRIF | USIC_PSCR_CAIF)
	ldr     r3, [r2, #USIC_PSCR]
	orr     r3, r1
	str     r3, [r2, #USIC_PSCR]

    ldr     r1, =USIC_RBUF
	ldrb    r3, [r2, r1]
	strb    r3, [r0]

	bx      lr
	.end
