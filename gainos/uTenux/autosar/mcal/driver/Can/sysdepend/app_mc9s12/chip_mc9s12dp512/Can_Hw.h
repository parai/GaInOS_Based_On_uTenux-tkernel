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
#ifndef CAN_HW_H_
#define CAN_HW_H_
#include "Can_Types.h"
typedef enum {
	CAN_CTRL_0 = 0,
	CAN_CTRL_1 = 1,
	CAN_CTRL_2 = 2,
	CAN_CTRL_3 = 3,
	CAN_CTRL_4 = 4,
	CAN_CONTROLLER_CNT = 5
}CanControllerIdType;

/** Start mc9s12 unique */
typedef enum {
  CAN_IDAM_2_32BIT,
  CAN_IDAM_4_16BIT,
  CAN_IDAM_8_8BIT,
  CAN_IDAM_FILTER_CLOSED,
} Can_IDAMType;

typedef struct {
	void (*CancelTxConfirmation)( const Can_PduType *);
	void (*RxIndication)( uint8 ,Can_IdType ,uint8 , const uint8 * );
	void (*ControllerBusOff)(uint8);
	void (*TxConfirmation)(PduIdType);
	void (*ControllerWakeup)(uint8);
	void (*Arc_Error)(uint8,Can_Arc_ErrorType);
} Can_CallbackType;
typedef struct
{
	uint8 idmr[8]; /* Identifier Mask Register, 1 = ignore corresponding acceptance code register bit*/
	uint8 idar[8]; /* Identifier Acceptance Register*/
	Can_IDAMType idam;
} Can_FilterMaskType;

typedef struct Can_HardwareObjectStruct {
	/** Specifies the type (Full-CAN or Basic-CAN) of a hardware object.*/
	Can_HandleType CanHandleType;

	/** Specifies whether the IdValue is of type - standard identifier - extended
	identifier - mixed mode ImplementationType: Can_IdType*/
	Can_IdTypeType CanIdType;

	/**	Specifies (together with the filter mask) the identifiers range that passes
	the hardware filter.*/
	uint32 CanIdValue;

	/**	Holds the handle ID of HRH or HTH. The value of this parameter is unique
	in a given CAN Driver, and it should start with 0 and continue without any
	gaps. The HRH and HTH Ids are defined under two different name-spaces.
	Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3.*/
	uint16 CanObjectId;

	/** Specifies if the HardwareObject is used as Transmit or as Receive object*/
	Can_ObjectTypeType CanObjectType;

	/** Reference to the filter mask that is used for hardware filtering togerther
	with the CAN_ID_VALUE*/
	Can_FilterMaskType *CanFilterMaskRef;

	/** A "1" in this mask tells the driver that that HW Message Box should be
	occupied by this Hoh. A "1" in bit 31(ppc) occupies Mb 0 in HW.*/
	uint32 Can_Arc_MbMask;

	/** End Of List. Set to TRUE is this is the last object in the list.*/
	boolean Can_Arc_EOL;
} Can_HardwareObjectType;

typedef struct
{
	/** Enables / disables API Can_MainFunction_BusOff() for
	handling busoff events in polling mode. */
	Can_ProcessType CanBusoffProcessing;
	/** Defines if a CAN controller is used in the configuration. */
	boolean         CanControllerActivation;
	/** This parameter provides the controller ID which is unique in a
	given CAN Driver. The value for this parameter starts with 0 and
	continue without any gaps. */
	CanControllerIdType  CanControllerId;
	/** Enables / disables API Can_MainFunction_Read() for
	handling PDU reception events in polling mode. */
	Can_ProcessType CanRxProcessing;
	/** Enables / disables API Can_MainFunction_Write() for
	handling PDU transmission events in polling mode.  */
	Can_ProcessType CanTxProcessing;
	/** Enables / disables API Can_MainFunction_Wakeup() for
	handling wakeup events in polling mode. */
	Can_ProcessType CanWakeupProcessing;
	/** CAN driver support for wakeup over CAN Bus. */
	boolean         CanWakeupSupport;
	/**	Reference to the CPU clock configuration, which is set in the MCU driver
	configuration.*/
	uint32 CanCpuClockRef;
	/** This parameter contains a reference to the Wakeup Source for this
	ontroller as defined in the ECU State Manager. Implementation Type:
	reference to EcuM_WakeupSourceType.*/
	uint32/* ref to EcuMWakeupSource */ CanWakeupSourceRef;
	/** Specifies the baudrate of the controller in kbps. */
	UINT            CanControllerBaudRate;
	/** Specifies propagation delay in time quantas.*/
	uint32          CanControllerPropSeg;
	/** Specifies phase segment 1 in time quantas.*/
	uint32          CanControllerSeg1;
	/** Specifies phase segment 2 in time quantas.*/
	uint32          CanControllerSeg2;
	/**	Specifies the synchronization jump width for the controller in
	time quantas.*/
	uint32          CanControllerSyncJumpWidth;
	/** List of Hoh id's that belong to this controller */
	const Can_HardwareObjectType  *Can_Hoh;
}Can_ControllerConfigType;

typedef struct {
	const Can_ControllerConfigType *CanController;

	/* Callbacks( Extension )*/
	const Can_CallbackType *CanCallbacks;
} Can_ConfigSetType;

/*
	This is  the type of the external data structure containing the overall initialization
	data for the CAN driver and SFR settings affecting all controllers. Furthermore it
	contains pointers to controller configuration structures. The contents of the
	initialization data structure are CAN hardware specific.
*/
typedef struct
{
	/** This is the multiple configuration set container for CAN Driver
	 Multiplicity 1..*  */
	const Can_ConfigSetType	 *CanConfigSet;
}Can_ConfigType;


#endif /* CAN_HW_H_ */
