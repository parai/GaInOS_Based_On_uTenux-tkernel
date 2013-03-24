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
#include "CanIf_Cbk.h"
#include "EcuM_Cbk.h"
#include "osek_os.h"
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
typedef struct{
	Can_DriverStateType driverState;
	const Can_ConfigType* config;
}Can_GlobalType;

LOCAL Can_GlobalType Can_Global =
{
		CAN_UNINIT, 	/* driverState */
};

EXPORT void Can_Init(const Can_ConfigType* Config)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT != Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INIT_SERVICE_ID,CAN_E_TRANSITION);
		return;
	}
	if(NULL == Config)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INIT_SERVICE_ID,CAN_E_PARAM_POINTER);
		return;
	}
#endif

}

#if(CAN_VERSION_INFO_API == STD_ON )
EXPORT void Can_GetVersionInfo(Std_VersionInfoType* versioninfo )
{
	STD_GET_VERSION_INFO(versioninfo,CAN);
}
#endif

EXPORT void Can_InitController(uint8 Controller,const Can_ControllerBaudrateConfigType* Config)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INITCONTROLLER_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
	if(NULL == Config)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INITCONTROLLER_SERVICE_ID,CAN_E_PARAM_POINTER);
		return;
	}
#endif
}

EXPORT Can_ReturnType Can_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_SETCONTROLLERMODE_SERVICE_ID,CAN_E_UNINIT);
		return CAN_NOT_OK;
	}
	if((Transition > CAN_T_WAKEUP) || (Transition <CAN_T_START))
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_SETCONTROLLERMODE_SERVICE_ID,CAN_E_TRANSITION);
		return CAN_NOT_OK;
	}
#endif
}
EXPORT void Can_DisableControllerInterrupts(uint8 Controller)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}

EXPORT void Can_EnableControllerInterrupts(uint8 Controller)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}

EXPORT Can_ReturnType Can_CheckWakeup(uint8 Controller)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_CBK_CHECKWAKEUP_SERVICE_ID,CAN_E_UNINIT);
		return CAN_NOT_OK;
	}
#endif
}

EXPORT Can_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_WRITE_SERVICE_ID,CAN_E_UNINIT);
		return CAN_NOT_OK;
	}
#endif
}

EXPORT void Can_MainFunction_Write(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_WRITE_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_Read(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_READ_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_BusOff(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_BUSOFF_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_WakeUp(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_WAKEUP_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_Mode(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_MODE_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}

