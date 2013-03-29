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

#include "Can.h"
#include "Can_Cfg.h"

LOCAL const Can_FilterMaskType  Can_FilterMaskCfgData[]=
{   
    {
        {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},  /*Mask ALL*/
        {0x0},
        CAN_IDAM_2_32BIT
    }
};
LOCAL const Can_HardwareObjectType Can0_HOHCfgDate[]=
{
    {  /*Tx*/
        CAN_HANDLE_BASIC,
        CAN_ID_TYPE_STANDARD,
        0,
        CAN0_HTH,   /* CanObjectId */
        CAN_OBJECT_TYPE_TRANSMIT,
        &Can_FilterMaskCfgData[0],
        0,
        FALSE       
    },
    {  /*Rx*/
        CAN_HANDLE_BASIC,
        CAN_ID_TYPE_STANDARD,
        0,
        CAN0_HRH,    /* CanObjectId */
        CAN_OBJECT_TYPE_RECEIVE,
        &Can_FilterMaskCfgData[0],
        0,
        TRUE 
    }
};

LOCAL const Can_HardwareObjectType Can1_HOHCfgDate[]=
{
    {  /*Tx*/
        CAN_HANDLE_BASIC,
        CAN_ID_TYPE_STANDARD,
        0,
        CAN1_HTH,   /* CanObjectId */
        CAN_OBJECT_TYPE_TRANSMIT,
        &Can_FilterMaskCfgData[0],
        0,
        FALSE       
    },
    {  /*Rx*/
        CAN_HANDLE_BASIC,
        CAN_ID_TYPE_STANDARD,
        0,
        CAN1_HRH,    /* CanObjectId */
        CAN_OBJECT_TYPE_RECEIVE,
        &Can_FilterMaskCfgData[0],
        0,
        TRUE 
    }
};
LOCAL const Can_ControllerConfigType   Can_ControllerCfgData[]=
{
    {
        CAN_CTRL_0,
        CAN_PROCESS_TYPE_INTERRUPT,
        CAN_PROCESS_TYPE_INTERRUPT,
        CAN_PROCESS_TYPE_INTERRUPT,
        CAN_PROCESS_TYPE_INTERRUPT,
        250,    /* kbps */
        0,  /*SJW*/
        13, /* seg1 */
        2,  /* seg2 */
        Can0_HOHCfgDate,
        FALSE       
    },
    {
        CAN_CTRL_1,
        CAN_PROCESS_TYPE_INTERRUPT,
        CAN_PROCESS_TYPE_INTERRUPT,
        CAN_PROCESS_TYPE_INTERRUPT,
        CAN_PROCESS_TYPE_INTERRUPT,
        250,    /* kbps */
        0,  /*SJW*/
        13, /* seg1 */
        2,  /* seg2 */
        Can1_HOHCfgDate,
        FALSE       
    }
};

LOCAL const Can_ConfigSetType Can_ConfigSetData =
{
      Can_ControllerCfgData
}; 
EXPORT const Can_ConfigType Can_ConfigData =
{
    &Can_ConfigSetData
};
