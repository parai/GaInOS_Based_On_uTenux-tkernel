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

#define BUS_CLK (CPU_FREQUENCY*1000000)
#define BAUDRATE 19600
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
	  while (ESCI_A.SR.B.RDRF == 0) {}    /* Wait for receive data reg full = 1 */
	  ESCI_A.SR.R = 0x20000000;           /* Clear RDRF flag */
	  *buf++ = ESCI_A.DR.B.D;            /* Read byte of Data*/
	  size--;
	}

} 

