#include "Can.h"
#include "Can_Cfg.h"

LOCAL const Can_FilterMaskType vCanFilterMask0=
{
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0,0,0,0,0,0,0,0},
	CAN_IDAM_2_32BIT
};

LOCAL const Can_HardwareObjectType CAN_CTRL_0_HOHCfgData[]=
{
	{
		CAN_HANDLE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_0_vCanHohRx,
		CAN_OBJECT_TYPE_RECEIVE,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		FALSE
	},
	{
		CAN_HANDLE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_0_vCanHohTx,
		CAN_OBJECT_TYPE_TRANSMIT,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		TRUE
	},
};

LOCAL const Can_HardwareObjectType CAN_CTRL_1_HOHCfgData[]=
{
	{
		CAN_HANDLE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_1_vCanHohRx,
		CAN_OBJECT_TYPE_RECEIVE,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		FALSE
	},
	{
		CAN_HANDLE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_1_vCanHohTx,
		CAN_OBJECT_TYPE_TRANSMIT,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		TRUE
	},
};

LOCAL const Can_HardwareObjectType CAN_CTRL_4_HOHCfgData[]=
{
	{
		CAN_HANDLE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_4_vCanHohRx,
		CAN_OBJECT_TYPE_RECEIVE,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		FALSE
	},
	{
		CAN_HANDLE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_4_vCanHohTx,
		CAN_OBJECT_TYPE_TRANSMIT,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		TRUE
	},
};

LOCAL const Can_ControllerConfigType  Can_ControllerCfgData[]=
{
	{
		CAN_CTRL_0,		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		250, /* baudrate(kbs) */
		0, /* propseg(SJW) */
		13, /* seg1 */
		2, /* seg2 */
		CAN_CTRL_0_HOHCfgData,
		FALSE
	},
	{
		CAN_CTRL_1,		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		250, /* baudrate(kbs) */
		0, /* propseg(SJW) */
		13, /* seg1 */
		2, /* seg2 */
		CAN_CTRL_1_HOHCfgData,
		FALSE
	},
	{
		CAN_CTRL_4,		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		250, /* baudrate(kbs) */
		0, /* propseg(SJW) */
		13, /* seg1 */
		2, /* seg2 */
		CAN_CTRL_4_HOHCfgData,
		FALSE
	},
};
LOCAL const Can_ConfigSetType Can_ConfigSetData ={Can_ControllerCfgData};
EXPORT const Can_ConfigType Can_ConfigData ={&Can_ConfigSetData};
