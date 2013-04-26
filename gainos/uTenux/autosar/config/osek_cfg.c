#include "osek_cfg.h"

const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM]=
{
	GenResourceCreInfo(1),	/* vSchedulerResource */
};

/* Generate Task Stack */
GenTaskStack(vTaskInit,512);
GenTaskStack(vTaskMainFunction,512);
GenTaskStack(vTaskSender,512);
GenTaskStack(vTaskReceiver,512);
/* Generate Task Create Information */
const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM]=
{
	GenTaskCreInfo(vTaskInit,2,NULL),
	GenTaskCreInfo(vTaskMainFunction,4,NULL),
	GenTaskCreInfo(vTaskSender,5,NULL),
	GenTaskCreInfo(vTaskReceiver,5,NULL),
};
/* Is Task auto-startable */
const BOOL OsekTaskAuotStartable[cfgOSEK_TASK_NUM]=
{
	TRUE,	/* vTaskInit */
	FALSE,	/* vTaskMainFunction */
	FALSE,	/* vTaskSender */
	FALSE,	/* vTaskReceiver */
};

#include "PduR.h"
#include "CanTp.h"
#include "CanIf.h"
#include "Can.h"
#include "Com.h"
//#include "string.h"
TASK(vTaskInit)
{
	tm_putstring((UB*)"vTaskInit is running.\r\n");
	
	//Com 模块初始化
	Can_Init(&Can_ConfigData);
	CanIf_Init(&CanIf_Config);
	CanTp_Init();
	PduR_Init(&PduR_Config);
	Com_Init(&ComConfiguration);
	
    //Com 通道启动	
    CanIf_SetControllerMode(vCanIf_Channel0,CANIF_CS_STARTED);
	CanIf_SetControllerMode(vCanIf_Channel1,CANIF_CS_STARTED);
	
	// Make sure that the right PDU-groups are ready for communication.
	Com_IpduGroupStart(vCom_IPduGrp0, 0);
	
	//启动CanTp周期任务定时器，周期激活任务 ID_vTaskCanTpMainFunction
	//(void)SetRelAlarm(ID_vAlarmCanTp,1,1);//1个Tick 4ms
	(void)ActivateTask(ID_vTaskMainFunction);
	
	//启动任务
	(void)ActivateTask(ID_vTaskSender);
	(void)ActivateTask(ID_vTaskReceiver);
	(void)TerminateTask();
}
boolean IncommingFreqReq(PduIdType PduId, const uint8 *IPduData)
{
    tm_putstring((UB*)"IncommingFreqReq() is running.\r\n");
    return FALSE;
}
TASK(vTaskMainFunction)
{
	tm_putstring((UB*)"vTaskMainFunction is running.\r\n");
	
	for(;;){
	    CanTp_MainFunction();
	    Com_MainFunctionRx();
	    Com_MainFunctionTx();
	    DelayTask(1);
	}	
	//(void)TerminateTask();
}
    
TASK(vTaskSender)
{
    uint8 Singal1[3]={7,8,9};
    uint8 ack;
    
	tm_putstring((UB*)"vTaskSender is running.\r\n");
	
	for(;;)
	{
	    tm_printf("Send Signal is [%d,%d,%d].\r\n",Singal1[0],Singal1[1],Singal1[2]);
	    Com_SendSignal(vCom_IPdu0_Signal0,Singal1);
	    Com_TriggerIPduSend(vCom_IPdu0);
	    DelayTask(250*10); //沉睡10s后重启
	    Com_ReceiveSignal(vCom_IPdu1_Signal0,&ack);
	    tm_printf("Ack From vTaskReceiver is %d.\r\n",ack);
	    Singal1[0]++;
	    Singal1[1]++;
	    Singal1[2]++;	    
	}
	(void)TerminateTask();
}

TASK(vTaskReceiver)
{
    uint8 Singal1[3];
    uint8 ack = 0;
	tm_putstring((UB*)"vTaskReceiver is running.\r\n");
	DelayTask(250*5); //沉睡5s
	for(;;)
	{
	    Com_ReceiveSignal(vCom_IPdu3_Signal0,Singal1);
	    tm_printf("Received Signal is [%d,%d,%d].\r\n\r\n",Singal1[0],Singal1[1],Singal1[2]);
	    Com_SendSignal(vCom_IPdu2_Signal0,&ack);
	    Com_TriggerIPduSend(vCom_IPdu2);
	    DelayTask(250*10); //沉睡10s 
	    ack++;
	}
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
	(void)tk_sta_tsk(ID_vTaskMainFunction,ID_vTaskMainFunction);
}

