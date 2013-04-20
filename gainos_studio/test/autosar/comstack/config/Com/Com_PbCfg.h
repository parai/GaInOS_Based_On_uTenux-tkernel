#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 2)) )
#error Com: Configuration file expected BSW module version to be 1.2.*
#endif

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

#include "Com_Types.h"

extern const Com_ConfigType ComConfiguration;

// PDU group id definitions
#define vCom_IPduGrp0 0

//  COM IPDU Id Defines.
#define vCom_IPdu0 0
#define vCom_IPdu1 1
#define vCom_IPdu2 2
#define vCom_IPdu3 3
#define vCom_IPdu4 4
#define vCom_IPdu5 5

//General Signal (Group) Id defines
#define vCom_IPdu0_Signal0 0
#define vCom_IPdu0_SigGrp0 1
#define vCom_IPdu1_Signal0 2
#define vCom_IPdu1_SigGrp0 3
#define vCom_IPdu2_Signal0 4
#define vCom_IPdu2_SigGrp0 5
#define vCom_IPdu3_Signal0 6
#define vCom_IPdu3_SigGrp0 7
#define vCom_IPdu4_Signal0 8
#define vCom_IPdu4_Signal1 9
#define vCom_IPdu5_Signal0 10
#define vCom_IPdu5_Signal1 11

//Group Signal Id defines
#define vCom_IPdu0_SigGrp0_Signal0 0
#define vCom_IPdu0_SigGrp0_Signal1 1
#define vCom_IPdu1_SigGrp0_Signal0 2
#define vCom_IPdu1_SigGrp0_Signal1 3
#define vCom_IPdu2_SigGrp0_Signal0 4
#define vCom_IPdu2_SigGrp0_Signal1 5
#define vCom_IPdu3_SigGrp0_Signal0 6
#define vCom_IPdu3_SigGrp0_Signal1 7

// Notifications
extern void vCom_IPdu0_Signal0_Notification(void);
extern void vCom_IPdu0_Signal0_TimeoutNotification(void);
extern void vCom_IPdu0_SigGrp0_Notification(void);
extern void vCom_IPdu0_SigGrp0_TimeoutNotification(void);
extern void vCom_IPdu1_Signal0_Notification(void);
extern void vCom_IPdu1_Signal0_TimeoutNotification(void);
extern void vCom_IPdu1_SigGrp0_Notification(void);
extern void vCom_IPdu1_SigGrp0_TimeoutNotification(void);
extern void vCom_IPdu2_Signal0_Notification(void);
extern void vCom_IPdu2_Signal0_TimeoutNotification(void);
extern void vCom_IPdu2_SigGrp0_Notification(void);
extern void vCom_IPdu2_SigGrp0_TimeoutNotification(void);
extern void vCom_IPdu3_Signal0_Notification(void);
extern void vCom_IPdu3_Signal0_TimeoutNotification(void);
extern void vCom_IPdu3_SigGrp0_Notification(void);
extern void vCom_IPdu3_SigGrp0_TimeoutNotification(void);
extern void vCom_IPdu4_Signal0_Notification(void);
extern void vCom_IPdu4_Signal0_TimeoutNotification(void);
extern void vCom_IPdu4_Signal1_Notification(void);
extern void vCom_IPdu4_Signal1_TimeoutNotification(void);
extern void vCom_IPdu5_Signal0_Notification(void);
extern void vCom_IPdu5_Signal0_TimeoutNotification(void);
extern void vCom_IPdu5_Signal1_Notification(void);
extern void vCom_IPdu5_Signal1_TimeoutNotification(void);

// Callouts
extern boolean vCom_IPdu0_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu1_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu2_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu3_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu4_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu5_Callout(PduIdType PduId, const uint8 *IPduData);
#endif /* COM_PBCFG_H */

