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
 *    CPU:        AT91SAM3S4C
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : sio.S
 *	 Create Date    : 2011/02/11-2012/09/23
 *	 Author	        : WangShb-wangxd
 *	 Description    : serial port communication routine.
 *-------------------------------------------------------------------------------
 */

#include <machine.h>
#include <tk/asm.h>
#include "mc9s12dp512.h"
#define  BUS_CLOCK		   32000000	   //总线频率-
#define  OSC_CLOCK		   16000000	   //晶振频率
#define  BAUD 115200                   //串口波特率
/*
 *    Function Name : sio_init
 *    Create Date   : 2011/02/11-2012/09/23
 *    Author        : wangshb-wangxd
 *    Description   : init sio as Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
void sio_init(void)
{
    SCI0BD = BUS_CLOCK/16/BAUD;   //设置SCI0波特率为9600
    SCI0CR1 = 0x00;       //设置SCI0为正常模式，八位数据位，无奇偶校验
    SCI0CR2 = 0x08;       //允许发送数据，禁止中断功能 
}
/*
 *    Function Name : sio_send_frame
 *    Create Date   : 2011/02/11-2012/09/23
 *    Author        : wangshb-wangxd
 *    Description   : send char to sio
 *    Param	        : r0: buffer address to send
 *    Return Code   : none.
 */
void sio_send_frame( const unsigned char* buf, unsigned int size )
{
    while(size>0)
    {
      while(!SCI0SR1_TDRE);       //等待发送数据寄存器（缓冲器）为空
      SCI0DRL = *buf++;
      size--;
    }
} 
/*
 *    Function Name : sio_recv_frame
 *    Create Date   : 2011/02/11-2012/09/23
 *    Author        : wangshb-wangxd
 *    Description   : receive char from sio
 *    Param	        : none.
 *    Return Code   : r0: char to receive
 */
void sio_recv_frame( unsigned char* buf, unsigned int size )
{    
     while(size>0)
     {
         while(!SCI0SR1_RDRF);          //等待发送数据寄存器满
         *buf++ = SCI0DRL;
         size--;
     }
} 

