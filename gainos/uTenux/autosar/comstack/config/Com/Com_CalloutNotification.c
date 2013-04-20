#include "Com.h"
// Notifications
void vCom_IPdu0_Signal0_Notification(void){}
void vCom_IPdu0_Signal0_TimeoutNotification(void){}
void vCom_IPdu0_SigGrp0_Notification(void){}
void vCom_IPdu0_SigGrp0_TimeoutNotification(void){}
void vCom_IPdu1_Signal0_Notification(void){}
void vCom_IPdu1_Signal0_TimeoutNotification(void){}
void vCom_IPdu1_SigGrp0_Notification(void){}
void vCom_IPdu1_SigGrp0_TimeoutNotification(void){}
void vCom_IPdu2_Signal0_Notification(void){}
void vCom_IPdu2_Signal0_TimeoutNotification(void){}
void vCom_IPdu2_SigGrp0_Notification(void){}
void vCom_IPdu2_SigGrp0_TimeoutNotification(void){}
void vCom_IPdu3_Signal0_Notification(void){}
void vCom_IPdu3_Signal0_TimeoutNotification(void){}
void vCom_IPdu3_SigGrp0_Notification(void){}
void vCom_IPdu3_SigGrp0_TimeoutNotification(void){}
void vCom_IPdu4_Signal0_Notification(void){}
void vCom_IPdu4_Signal0_TimeoutNotification(void){}
void vCom_IPdu4_Signal1_Notification(void){}
void vCom_IPdu4_Signal1_TimeoutNotification(void){}
void vCom_IPdu5_Signal0_Notification(void){}
void vCom_IPdu5_Signal0_TimeoutNotification(void){}
void vCom_IPdu5_Signal1_Notification(void){}
void vCom_IPdu5_Signal1_TimeoutNotification(void){}

// Callouts
boolean vCom_IPdu0_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
boolean vCom_IPdu1_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
boolean vCom_IPdu2_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
boolean vCom_IPdu3_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
boolean vCom_IPdu4_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
boolean vCom_IPdu5_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
