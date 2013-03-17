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
 *    CPU:        MC9S12DP512
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *   Create Date    : 2013/3/15-2013/3/17
 *   Author         : Fan Wang(parai)
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>
#include "MPC5634M_MLQB80.h"

#define CPU_FREQUENCY  80
#define BUS_CLK (CPU_FREQUENCY*1000000)
#define BAUDRATE 115200

#define CPU_FREQUENCY  80
#if(CPU_FREQUENCY==8)
#define SYNCR_V 0x36100000
#endif
#if(CPU_FREQUENCY==16)
#define SYNCR_V 0x16100000
#endif
#if(CPU_FREQUENCY==20)
#define SYNCR_V 0x18100000
#endif
#if(CPU_FREQUENCY==32)
#define SYNCR_V 0x16080000
#endif
#if(CPU_FREQUENCY==40)
#define SYNCR_V 0x18080000
#endif
#if(CPU_FREQUENCY==50)
#define SYNCR_V 0x1A880000
#endif
#if(CPU_FREQUENCY==60)
#define SYNCR_V 0x15800000
#endif
#if(CPU_FREQUENCY==64)
#define SYNCR_V 0x16000000	/**PREFDIV=1,MFD=12,RFD=0,->Fsys=64MHZ*/
#endif
#if(CPU_FREQUENCY==80) /**PREFDIV=1,MFD=16,RFD=0,->Fsys=80MHZ*/
#define SYNCR_V 0x18000000
#endif

extern void OSTickISR(void);
void TickTimer_SetFreqHz(int Freq)
{
	int  decr=CPU_FREQUENCY*1000000/Freq;
	asm
	{
/**/
		li		r0, 0x0000	
		mthid0	r0
/*Set the gap time between tick and tick*/		
		lwz      r0,decr
		mtdec		r0
		mtdecar	r0			
/*Set TCR[DIE]=1,TCR[ARE]=1,that is to enable DEC interrupt and enable auto-reload*/
		lis		r0, 0x0440	
		mftcr     r3
		or        r0,r0,r3	
		mttcr		r0		
/*Set HID0[TBEN]=1,Time base enable*/			
		li		r0, 0x4000		
		mthid0	r0
	}
	asm
	{
	    lis     r0, OSTickISR@h
	    ori     r0, r0, OSTickISR@l
	    /* IVOR10 Decrementer interrupt (SPR 410) */
	    mtivor10 r0
	}
}
/**
 * Fref=8MHZ(CRYSTAL OSCILLATOR CLOCK)
 * In legacy mode:Fsys=Fref*(MFD+4)/(PREFDIV+1)/(2^RFD)
 * In enhanced mode:Fsys=Fref*(EMFD)/(EPREFDIV+1)/(2^(ERFD+1))
 */
void Cpu_FrequencyInit(void)
{
	FMPLL.ESYNCR1.B.CLKCFG = 0X7;
	FMPLL.SYNCR.R = 0x16080000;/**PREFDIV=1,MFD=12,RFD=1,->Fsys=32MHZ*/
	while (FMPLL.SYNSR.B.LOCK != 1) {};
	FMPLL.SYNCR.R = SYNCR_V;
}
/*
 *    Function Name : sio_init
 *   Create Date    : 2013/3/15-2013/3/17
 *   Author         : Fan Wang(parai)
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
void sio_init(void)
{
	ESCI_A.CR2.R = 0x2000;
	ESCI_A.CR1.R =(((BUS_CLK/(16*BAUDRATE))<<16)|0x0000000c);
    SIU.PCR[89].R = 0x400;
    SIU.PCR[90].R = 0x400;
}
/*
 *    Function Name : sio_send_frame
 *   Create Date    : 2013/3/15-2013/3/17
 *   Author         : Fan Wang(parai)
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
void sio_send_frame( const unsigned char* buf, unsigned int size )
{
	while(size>0)
	{
		while (ESCI_A.SR.B.TDRE == 0) {}      
		ESCI_A.SR.R = 0x80000000;             
		ESCI_A.DR.B.D = *buf++;	
		size--;
	}
  
} 
/*
 *    Function Name : sio_recv_frame
 *   Create Date    : 2013/3/15-2013/3/17
 *   Author         : Fan Wang(parai)
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : None
 */
void sio_recv_frame( unsigned char* buf, int size )
{   
	while(size >0)
	{
		while (ESCI_A.SR.B.RDRF == 0) {}                 
		*buf++=ESCI_A.DR.B.D;
		size--;
	}

} 

