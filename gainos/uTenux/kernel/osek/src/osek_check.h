#ifndef OSEK_CHECK_H_H
#define OSEK_CHECK_H_H
#include "osek_cfg.h"
#if(cfgOSEK_TASK_NUM > CFN_MAX_TSKID)
#  error "OSEK Error:cfgOSEK_TASK_NUM>CFN_MAX_TSKID,So you should config CFN_MAX_TSKID>cfgOSEK_TASK_NUM!"
#endif
#if(cfgOSEK_EVENTFLAG_NUM > CFN_MAX_FLGID)
#  error "OSEK Error:cfgOSEK_EVENTFLAG_NUM > CFN_MAX_FLGID,So you should config  FN_MAX_FLGID > cfgOSEK_EVENTFLAG_NUM!"
#endif
#if(cfgOSEK_ALARM_NUM > CFN_MAX_CYCID)
#  error "OSEK Error:cfgOSEK_ALARM_NUM > CFN_MAX_CYCID,So you should config CFN_MAX_CYCID > cfgOSEK_ALARM_NUM!"
#endif
#if(cfgOSEK_ALARM_NUM > CFN_MAX_ALMID)
#  error "OSEK Error:cfgOSEK_ALARM_NUM > CFN_MAX_ALMID,So you should config CFN_MAX_ALMID > cfgOSEK_ALARM_NUM!"
#endif
#if(cfgOSEK_RESOURCE_NUM > CFN_MAX_MTXID)
#  error "OSEK Error:cfgOSEK_RESOURCE_NUM > CFN_MAX_MTXID,So you should config CFN_MAX_MTXID > cfgOSEK_RESOURCE_NUM!"
#endif
#endif /* OSEK_CHECK_H_H */
