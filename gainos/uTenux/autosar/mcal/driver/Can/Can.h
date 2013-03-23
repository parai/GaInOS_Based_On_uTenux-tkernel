/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#ifndef _CAN_H_H
#define _CAN_H_H
#define CAN_VENDOR_ID			    1
#define CAN_MODULE_ID			    MODULE_ID_CAN
#define CAN_AR_MAJOR_VERSION  2
#define CAN_AR_MINOR_VERSION 	2
#define CAN_AR_PATCH_VERSION	2

#define CAN_SW_MAJOR_VERSION	1
#define CAN_SW_MINOR_VERSION 	0
#define CAN_SW_PATCH_VERSION	0
/* ##############################  INCLUDEs  ############################## */
#include "ComStack_Types.h"
#include "Can_Types.h"
#include "Can_Hw.h"
#include "Can_Cfg.h"

/* ##############################  MACROs  ############################## */
#define CAN_E_PARAM_POINTER     0x01
#define CAN_E_PARAM_HANDLE      0x02
#define CAN_E_PARAM_DLC     	0x03
#define CAN_E_PARAM_CONTROLLER  0x04
/* API service used without initialization */
#define CAN_E_UNINIT            0x05
/* Init transition for current mode */
#define CAN_E_TRANSITION        0x06

#define CAN_E_DATALOST          0x07     /** @req 4.0/CAN395 */

/** name Service id's */
#define CAN_INIT_SERVICE_ID                         0x00
#define CAN_MAINFUNCTION_WRITE_SERVICE_ID           0x01
#define CAN_INITCONTROLLER_SERVICE_ID               0x02
#define CAN_SETCONTROLLERMODE_SERVICE_ID            0x03
#define CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID  0x04
#define CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID   0x05
#define CAN_WRITE_SERVICE_ID                        0x06
#define CAN_GETVERSIONINFO_SERVICE_ID               0x07
#define CAN_MAINFUNCTION_READ_SERVICE_ID            0x08
#define CAN_MAINFUNCTION_BUSOFF_SERVICE_ID          0x09
#define CAN_MAINFUNCTION_WAKEUP_SERVICE_ID          0x0a
#define CAN_CBK_CHECKWAKEUP_SERVICE_ID              0x0b
#define CAN_MAINFUNCTION_MODE_SERVICE_ID            0x0c

/* ##############################  FUNCTIONs  ############################## */
IMPORT void Can_Init(const Can_ConfigType* Config);
IMPORT void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);
IMPORT void Can_InitController(uint8 Controller,const Can_ControllerBaudrateConfigType* Config);
IMPORT Can_ReturnType Can_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition);
IMPORT void Can_DisableControllerInterrupts(uint8 Controller);
IMPORT Can_ReturnType Can_CheckWakeup(uint8 Controller);
IMPORT Can_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo);
#endif /* _CAN_H_H */
