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
#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/* ################ Can General ################ */
#define CAN_DEV_ERROR_DETECT  STD_ON
#define CAN_VERSION_INFO_API  STD_ON
#define CAN_HW_TRANSMIT_CANCELLATION   STD_OFF
#define CAN_IDENTICAL_ID_CANCELLATION  STD_OFF
#define CAN_MULTIPLEXED_TRANSMISSION   STD_OFF

/* unit is ms */
#define CanMainFunctionBusoffPeriod  10
#define CanMainFunctionModePeriod    10
#define CanMainFunctionReadPeriod    10
#define CanMainFunctionWakeupPeriod  10
#define CanMainFunctionWritePeriod   10
#define CAN_TIMEOUT_DURATION         10
#define cfgCAN_EXTEND         STD_OFF

typedef enum {
	TxHWObject,
	NUM_OF_HTHS
} Can_HTHType;

/* Number of controller configs */
#define CAN_CTRL_CONFIG_CNT		1

#endif /* CAN_CFG_H_ */
