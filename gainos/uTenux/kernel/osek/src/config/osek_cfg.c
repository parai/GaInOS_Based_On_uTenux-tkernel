#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vSchedulerResource */
};

/* Generate Task Stack */
GenTaskStack(vTaskInit,512);
GenTaskStack(vTaskCanTpMainFunction,512);
GenTaskStack(vTaskSender,512);
GenTaskStack(vTaskReceiver,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTaskInit,2,NULL),
	GenTaskCreInfo(vTaskCanTpMainFunction,4,NULL),
	GenTaskCreInfo(vTaskSender,5,NULL),
	GenTaskCreInfo(vTaskReceiver,5,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTaskInit */
	FALSE,	/* vTaskCanTpMainFunction */
	FALSE,	/* vTaskSender */
	FALSE,	/* vTaskReceiver */
};

#include "PduR.h"
#include "CanTp.h"
#include "CanIf.h"
#include "Can.h"
#include "string.h"
TASK(vTaskInit)
{
	tm_putstring((UB*)"vTaskInit is running.\r\n");
	
	//Com 模块初始化
	Can_Init(&Can_ConfigData);
	CanIf_Init(&CanIf_Config);
	CanTp_Init();
	PduR_Init(&PduR_Config);
	
    //Com 通道启动	
	CanIf_SetControllerMode(vCanIf_Channel0,CANIF_CS_STARTED);
	CanIf_SetControllerMode(vCanIf_Channel1,CANIF_CS_STARTED);
	
	//启动CanTp周期任务定时器，周期激活任务 ID_vTaskCanTpMainFunction
	//(void)SetRelAlarm(ID_vAlarmCanTp,1,1);//1个Tick 4ms
	(void)ActivateTask(ID_vTaskCanTpMainFunction);
	
	//启动任务
	(void)ActivateTask(ID_vTaskSender);
	(void)ActivateTask(ID_vTaskReceiver);
	(void)TerminateTask();
}

TASK(vTaskCanTpMainFunction)
{
	tm_putstring((UB*)"vTaskCanTpMainFunction is running.\r\n");
	
	for(;;){
	    CanTp_MainFunction();
	    DelayTask(1);
	}	
	//(void)TerminateTask();
}

const UB* G_Message = "I am parai.\r\n"
    "Try to port the com of ArcCore on GaInOS.\r\n"
    "I wish a Success.\r\n";
    
PduInfoType G_TxPdu;    
TASK(vTaskSender)
{
    PduInfoType pdu;
    
	tm_putstring((UB*)"vTaskSender is running.\r\n");
	
	G_TxPdu.SduLength  = strlen(G_Message);
	G_TxPdu.SduDataPtr = G_Message;
	for(;;)
	{
	    CanTp_Transmit(CANTP_TX_vEcuC_Pdu0,&G_TxPdu);
	    DelayTask(250*60); //沉睡1分钟后重启
	}
	(void)TerminateTask();
}

TASK(vTaskReceiver)
{
	tm_putstring((UB*)"vTaskReceiver is running.\r\n");
	(void)TerminateTask();
}

ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM]=
{
	AlarmCallBackEntry(vAlarmCanTp),
};
ALARMCALLBACK(vAlarmCanTp)
{
	(void)tk_sta_tsk(ID_vTaskCanTpMainFunction,ID_vTaskCanTpMainFunction);
}

