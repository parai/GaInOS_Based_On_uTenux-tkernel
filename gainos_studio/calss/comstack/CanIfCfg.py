# -*- coding: utf-8 -*-
"""
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
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString

from Common import *
import os, sys
import shutil 
from time import localtime, time,strftime
class CanIfGeneral():
    def __init__(self):
        self.DevErrorDetection=False;
        self.VersionInfoApi = False;
        self.DlcCheck=True;
        self.RuntimePduConfig=False;
        self.BusoffNotification='CanIf_User_BusoffNotification';
        self.ErrorNotification='CanIf_User_ErrorNotification';
        self.SoftwareFilterType='CANIF_SOFTFILTER_TYPE_MASK';

class CanIfRxPdu():
    def __init__(self, name):
        self.name=name;
        self.type='rxPdu'
        self.canType='CANIF_PDU_TYPE_STATIC';
        self.canId=0;
        self.canIdMask='0x7FF';
        self.canIdType='CANIF_CAN_ID_TYPE_11';
        self.dlc=8;
        self.indicationType='CAN_PDUR';
        self.userIndication='CanIf_UserRxIndication'

class CanIfTxPdu():
    def __init__(self, name):
        self.name=name;
        self.type='txPdu'
        self.canType='CANIF_PDU_TYPE_STATIC';
        self.canId=0;
        self.canIdType='CANIF_CAN_ID_TYPE_11';
        self.dlc=8;
        self.confirmation='NULL';

class CanIfHth():
    def __init__(self, name):
        self.name=name;
        self.type='hth';
        self.hohType='CAN_ARC_HANDLE_TYPE_BASIC';
        self.hohIdSymRef='';
        self.pduList=[];

class CanIfHrh():
    def __init__(self, name):
        self.name=name;
        self.type='hrh';
        self.hohType='CAN_ARC_HANDLE_TYPE_BASIC';
        self.hohIdSymRef='';
        self.softwareFilter=False;
        self.pduList=[];

class CanIfChannel():
    def __init__(self, name):
        self.name=name;
        self.canHwCtrl='';
        self.hthList=[];
        self.hrhList=[];

class CanIfConfig():
    def __init__(self):
        self.General=CanIfGeneral();
        self.channelList=[];

from CanIf_Dlg import CanIf_Dlg
class CanIfObj():
    def __init__(self):
        self.cfg=CanIfConfig();
        print "init CanIf Object"

    def toString(self):
        str='  Double Clicked to Start to Configure the Can Interface!\n';
        return str;

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;
    
    def show(self, cfg):
        depinfo=[];
        obj=self.findObj(cfg.arobjList, 'Can');
        if(obj==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure Can Firstly!').exec_();
            return;
        depinfo.append(obj.arobj);
        obj=self.findObj(cfg.arobjList, 'EcuC');
        if(obj==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(obj.arobj);
        dlg=CanIf_Dlg(self.cfg, depinfo);
        dlg.exec_();

    def saveGeneral(self, fp):
        fp.write('<CanIfGeneral>\n');
        fp.write('<DevErrorDetection value="%s"></DevErrorDetection>\n'%(self.cfg.General.DevErrorDetection));
        fp.write('<VersionInfoApi value="%s"></VersionInfoApi>\n'%(self.cfg.General.DevErrorDetection));
        fp.write('<DlcCheck value="%s"></DlcCheck>\n'%(self.cfg.General.DlcCheck));
        fp.write('<RuntimePduConfig value="%s"></RuntimePduConfig>\n'%(self.cfg.General.RuntimePduConfig));
        fp.write('<BusoffNotification value="%s"></BusoffNotification>\n'%(self.cfg.General.BusoffNotification));
        fp.write('<ErrorNotification value="%s"></ErrorNotification>\n'%(self.cfg.General.ErrorNotification));
        fp.write('<SoftwareFilterType value="%s"></SoftwareFilterType>\n'%(self.cfg.General.SoftwareFilterType));
        fp.write('</CanIfGeneral>\n');

    def saveTxPdu(self, fp, pdu):
        attrib='name="%s" '%(pdu.name);
        attrib+='type="%s" '%(pdu.type);
        attrib+='canType="%s" '%(pdu.canType);
        attrib+='canId="%s" '%(pdu.canId);
        attrib+='canIdType="%s" '%(pdu.canIdType);
        attrib+='dlc="%s" '%(pdu.dlc);
        attrib+='confirmation="%s" '%(pdu.confirmation);
        fp.write("<CanIfTxPdu %s>\n"%(attrib));
        fp.write("</CanIfTxPdu>\n");
        
    def saveHth(self,fp, hth):
        attrib='name="%s" '%(hth.name);
        attrib+='type="%s" '%(hth.type);
        attrib+='hohType="%s" '%(hth.hohType);
        attrib+='hohIdSymRef="%s" '%(hth.hohIdSymRef);
        fp.write("<CanIfHth %s>\n"%(attrib));
        fp.write("<CanIfTxPduList>\n");
        for pdu in hth.pduList:
            self.saveTxPdu(fp, pdu);
        fp.write("</CanIfTxPduList>\n");
        fp.write("</CanIfHth>\n");

    def saveRxPdu(self, fp, pdu):
        attrib='name="%s" '%(pdu.name);
        attrib+='type="%s" '%(pdu.type);
        attrib+='canType="%s" '%(pdu.canType);
        attrib+='canId="%s" '%(pdu.canId);
        attrib+='canIdMask="%s" '%(pdu.canIdMask);
        attrib+='canIdType="%s" '%(pdu.canIdType);
        attrib+='dlc="%s" '%(pdu.dlc);
        attrib+='indicationType="%s" '%(pdu.indicationType);
        attrib+='userIndication="%s" '%(pdu.userIndication);
        fp.write("<CanIfRxPdu %s>\n"%(attrib));
        fp.write("</CanIfRxPdu>\n");
        
    def saveHrh(self,fp, hrh):
        attrib='name="%s" '%(hrh.name);
        attrib+='type="%s" '%(hrh.type);
        attrib+='hohType="%s" '%(hrh.hohType);
        attrib+='hohIdSymRef="%s" '%(hrh.hohIdSymRef);
        attrib+='softwareFilter="%s" '%(hrh.softwareFilter);
        fp.write("<CanIfHrh %s>\n"%(attrib));
        fp.write("<CanIfRxPduList>\n");
        for pdu in hrh.pduList:
            self.saveRxPdu(fp, pdu);
        fp.write("</CanIfRxPduList>\n");
        fp.write("</CanIfHrh>\n");

    def saveChannel(self, fp, obj):
        attrib='name="%s" '%(obj.name);
        attrib+='canHwCtrl="%s" '%(obj.canHwCtrl);
        fp.write('<CanIfChannel %s>\n'%(attrib));
        fp.write("<CanIfHthList>\n");
        for hth in obj.hthList:
            self.saveHth(fp, hth);
        fp.write("</CanIfHthList>\n");
        fp.write("<CanIfHrhList>\n");
        for hrh in obj.hrhList:
            self.saveHrh(fp, hrh);
        fp.write("</CanIfHrhList>\n");
        fp.write('</CanIfChannel>\n'); 

    def saveChannelList(self, fp):
        fp.write('<CanIfChannelList>\n');
        for obj in self.cfg.channelList:
            self.saveChannel(fp, obj);
        fp.write('</CanIfChannelList>\n');

    def save(self, fp):
        """保存配置信息"""
        self.saveGeneral(fp);
        self.saveChannelList(fp);

    def doParseGeneral(self, list):
        self.cfg.General.DevErrorDetection=bool(list.find('DevErrorDetection').attrib['value']);
        self.cfg.General.VersionInfoApi=bool(list.find('VersionInfoApi').attrib['value']);
        self.cfg.General.DlcCheck=bool(list.find('DlcCheck').attrib['value']);
        self.cfg.General.RuntimePduConfig=bool(list.find('RuntimePduConfig').attrib['value']);
        self.cfg.General.BusoffNotification=list.find('BusoffNotification').attrib['value'];
        self.cfg.General.ErrorNotification=list.find('ErrorNotification').attrib['value'];
        self.cfg.General.SoftwareFilterType=list.find('SoftwareFilterType').attrib['value'];

    def doParseTxPdu(self, node):
        pdu=CanIfTxPdu(node.attrib['name']);
        pdu.type='txPdu'
        pdu.canType=node.attrib['canType'];
        pdu.canId=int(node.attrib['canId']);
        pdu.canIdType=node.attrib['canIdType'];
        pdu.dlc=int(node.attrib['dlc']);
        pdu.confirmation=node.attrib['confirmation'];
        return pdu;

    def doParseHth(self, node):
        hth=CanIfHth(node.attrib['name']);
        hth.type='hth';
        hth.hohType=node.attrib['hohType'];
        hth.hohIdSymRef=node.attrib['hohIdSymRef'];
        for nd in node.find('CanIfTxPduList'):
            hth.pduList.append(self.doParseTxPdu(nd));
        return hth;

    def doParseRxPdu(self, node):
        pdu=CanIfRxPdu(node.attrib['name']);
        pdu.type='rxPdu'
        pdu.canType=node.attrib['canType'];
        pdu.canId=int(node.attrib['canId']);
        pdu.canIdMask=node.attrib['canIdMask'];
        pdu.canIdType=node.attrib['canIdType'];
        pdu.dlc=int(node.attrib['dlc']);
        pdu.indicationType=node.attrib['indicationType'];
        pdu.userIndication=node.attrib['userIndication'];
        return pdu;

    def doParseHrh(self, node):
        hth=CanIfHth(node.attrib['name']);
        hth.type='hrh';
        hth.hohType=node.attrib['hohType'];
        hth.hohIdSymRef=node.attrib['hohIdSymRef'];
        hth.softwareFilter=bool(node.attrib['softwareFilter']);
        for nd in node.find('CanIfRxPduList'):
            hth.pduList.append(self.doParseRxPdu(nd));
        return hth;

    def doParseChannel(self, node):
        channel = CanIfChannel(node.attrib['name']);
        channel.canHwCtrl=node.attrib['canHwCtrl'];
        for nd in node.find('CanIfHthList'):
            channel.hthList.append(self.doParseHth(nd));
        for nd in node.find('CanIfHrhList'):
            channel.hrhList.append(self.doParseHrh(nd));
        return channel;

    def doParseChannelList(self, list):
        for node in list:
            self.cfg.channelList.append(self.doParseChannel(node));

    def doParse(self, arxml):
        self.doParseGeneral(arxml.find('CanIfGeneral'));
        self.doParseChannelList(arxml.find('CanIfChannelList'));

    def codeGen(self, path):
        path1=path+'/autosar/comstack/config/CanIf';
        try:
            os.mkdir(path+'/autosar');
        except:
            print "nothing serious!file already exists."
        try:
            os.mkdir(path+'/autosar/comstack');
        except:
            print "nothing serious!file already exists."
        try:
            os.mkdir(path+'/autosar/comstack/config');
        except:
            print "nothing serious!file already exists."
        try:
            os.mkdir(path+'/autosar/comstack/config/CanIf');
        except:
            print "nothing serious!file already exists."
        self.codeGenH(path1);
        self.codeGenC(path1);

    def backup(self, file):
        tm=localtime(time());
        file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
        shutil.copy(file, file2+'.bak');

    def codeGenH(self, path):
        file=path+'/CanIf_Cfg.h';
        if os.path.isfile(file) and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#ifndef CANIF_CFG_H_\n#define CANIF_CFG_H_\n\n#include "Can.h"\n\n');
        fp.write('#define CANIF_VERSION_INFO_API   %s\n'%(gSTD_ON(self.cfg.General.VersionInfoApi)));
        fp.write('#define CANIF_DEV_ERROR_DETECT   %s\n'%(gSTD_ON(self.cfg.General.DevErrorDetection)));
        fp.write('#define CANIF_DLC_CHECK          %s\n'%(gSTD_ON(self.cfg.General.DlcCheck)));
        ns= '#define CANIF_MULITPLE_DRIVER_SUPPORT       STD_OFF   // Not supported\n';
        ns+='#define CANIF_READRXPDU_DATA_API			 STD_OFF   // Not supported\n';
        ns+='#define CANIF_READRXPDU_NOTIFY_STATUS_API	 STD_OFF   // Not supported\n';
        ns+='#define CANIF_READTXPDU_NOTIFY_STATUS_API	 STD_OFF   // Not supported\n';
        ns+='#define CANIF_SETDYNAMICTXID_API            STD_OFF   // Not supported\n';
        ns+='#define CANIF_WAKEUP_EVENT_API			     STD_OFF   // Not supported\n';
        ns+='#define CANIF_TRANSCEIVER_API               STD_OFF   // Not supported\n';
        ns+='#define CANIF_TRANSMIT_CANCELLATION         STD_OFF   // Not supported\n';
        ns+='#define CANIF_ARC_RUNTIME_PDU_CONFIGURATION %s   // Not supported\n'%(gSTD_ON(self.cfg.General.RuntimePduConfig));
        ns+='#define CANIF_CANPDUID_READDATA_API         STD_OFF   // Not supported\n';
        ns+='#define CANIF_READRXPDU_NOTIF_STATUS_API    STD_OFF   // Not supported\n\n';
        fp.write(ns);
        fp.write('#define USE_PDUR\n');
        fp.write('#define USE_CANTP\n\n');
        #TX PDU ID
        fp.write('/* Tx PduId For CanIF */\n')
        index=0;
        for channel in self.cfg.channelList:
            for hth in channel.hthList:
                for pdu in hth.pduList:
                    fp.write('#define CANIF_%s\t\t%s\n'%(pdu.name,index));
                    index+=1;
        #RX PDU ID
        fp.write('/* Rx PduId For CanIF */\n')
        index=0;
        for channel in self.cfg.channelList:
            for hrh in channel.hrhList:
                for pdu in hrh.pduList:
                    fp.write('#define CANIF_%s\t\t%s\n'%(pdu.name,index));
                    index+=1;
        fp.write('// Identifiers for the elements in CanIfControllerConfig[]\n// This is the ConfigurationIndex in CanIf_InitController()\n');
        str=str2='';
        for channel in self.cfg.channelList:
            str+='\t%s_CONFIG_0,\n'%(channel.name);
            str2+='\t%s,\n'%(channel.name);
        str+='\tCANIF_CHANNEL_CONFIGURATION_CNT\n';
        str2+='\tCANIF_CHANNEL_CNT\n';
        fp.write('typedef enum {\n%s}CanIf_Arc_ConfigurationIndexType;\n\n'%(str));
        fp.write('typedef enum {\n%s}CanIf_Arc_ChannelIdType;\n\n'%(str2));
        fp.write('#include "CanIf_ConfigTypes.h"\n\nIMPORT const CanIf_ConfigType CanIf_Config;\n\n#endif\n\n');
        fp.close();

    def codeGenC(self, path):
        file=path+'/CanIf_Cfg.c';
        if os.path.isfile(file) and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#include "CanIf.h"\n');
        fp.write('#if defined(USE_CANTP)\n');
        fp.write('#include "CanTp.h"\n');
        fp.write('#include "CanTp_Cbk.h"\n');
        fp.write('#endif\n');
        fp.write('#if defined(USE_J1939TP)\n');
        fp.write('#include "J1939Tp.h"\n');
        fp.write('#include "J1939Tp_Cbk.h"\n');
        fp.write('#endif\n');
        fp.write('#if defined(USE_PDUR)\n');
        fp.write('#include "PduR.h"\n');
        fp.write('#endif\n');
        fp.write('#if defined(USE_CANNM)\n');
        fp.write('#include "CanNm_Cbk.h"\n');
        fp.write('#endif\n');
        fp.write('#include <stdlib.h>\n\n');
        fp.write('// Imported structs from Can_PBcfg.c\n');
        fp.write('IMPORT const Can_ControllerConfigType Can_ControllerCfgData[];\n');
        fp.write('IMPORT const Can_ConfigSetType Can_ConfigSetData;\n\n');
        #gen Notification
        fp.write('extern void CanIf_UserRxIndication(uint8 channel, PduIdType pduId, const uint8 *sduPtr,uint8 dlc, Can_IdType canId);\n')
        if(self.cfg.General.BusoffNotification!='NULL'):
            fp.write('void %s(uint8 Controller){}\n'%(self.cfg.General.BusoffNotification));
        if(self.cfg.General.ErrorNotification!='NULL'):
            fp.write('void %s(uint8 Controller,Can_Arc_ErrorType Error){}\n\n'%(self.cfg.General.ErrorNotification));
        #map channel and can controllor
        fp.write('// Contains the mapping from CanIf-specific Channels to Can Controllers\n');
        fp.write('const Can_ControllerIdType CanIf_Arc_ChannelToControllerMap[CANIF_CHANNEL_CNT] = {\n');
        str='';
        for channel in self.cfg.channelList:
            str+='\t%s,\t/* %s */\n'%(channel.canHwCtrl, channel.name);
        fp.write(str);
        fp.write('};\n\n');
        #map channel and configure index
        fp.write('const uint8 CanIf_Arc_ChannelDefaultConfIndex[CANIF_CHANNEL_CNT] = {\n');
        str='';
        for channel in self.cfg.channelList:
            str+='\t%s_CONFIG_0,\n'%(channel.name);
        fp.write(str);
        fp.write('};\n\n');
        #channel config
        fp.write('// Container that gets slamed into CanIf_InitController()\n');
        fp.write('// Inits ALL controllers\n');
        fp.write('// Multiplicity 1/*/**\n');
        fp.write('const CanIf_ControllerConfigType CanIfControllerConfig[] = {\n');
        fp.write('\t// This is the ConfigurationIndex in CanIf_InitController()\n');
        str='';
        for channel in self.cfg.channelList:
            str+='\t{\n';
            str+='\t\t/*WakeupSupport =*/ CANIF_WAKEUP_SUPPORT_NO_WAKEUP,\n';
            str+='\t\t/*CanIfControllerIdRef =*/ %s,\n'%(channel.name);
            str+='\t\t/*CanIfDriverNameRef =*/ "FLEXCAN",  // Not used\n';
            str+='\t\t/*CanIfInitControllerRef =*/ &Can_ControllerCfgData[INDEX_OF_%s],\n'%(channel.canHwCtrl);
            str+='\t},\n'
        fp.write(str);
        fp.write('};\n\n');
        #DISPATCH CALLBACK
        fp.write('// Function callbacks for higher layers\n');
        fp.write('const CanIf_DispatchConfigType CanIfDispatchConfig =\n{\n');
        str='\t/*CanIfBusOffNotification =*/ %s,\n'%(self.cfg.General.BusoffNotification);
        str+='\t/*CanIfWakeUpNotification =*/ NULL,        // Not used\n';
        str+='\t/*CanIfWakeupValidNotification =*/ NULL,   // Not used\n';
        str+='\t/*CanIfErrorNotificaton =*/ %s,\n'%(self.cfg.General.ErrorNotification);
        fp.write(str);
        fp.write('};\n\n');
        #CanIfInitConfiguration
        fp.write('// Data for init configuration CanIfInitConfiguration\n\n');
        for channel in self.cfg.channelList:
            hths='const CanIf_HthConfigType CanIfHthConfigData_%s[]=\n{\n'%(channel.name);
            eol=0;
            for hth in channel.hthList:
                eol+=1;
                hths+='\t{\n'
                hths+='\t\t/*CanIfHthType =*/ %s,\n'%(hth.hohType);
                hths+='\t\t/*CanIfCanControllerIdRef =*/ %s,\n'%(channel.name);
                hths+='\t\t/*CanIfHthIdSymRef =*/ %s,\n'%(hth.hohIdSymRef);
                if(eol==len(channel.hthList)):
                    hths+='\t\t/*CanIf_Arc_EOL =*/ TRUE\n'
                else:
                    hths+='\t\t/*CanIf_Arc_EOL =*/ FALSE\n'
                hths+='\t},\n'
            hths+='};\n\n'
            fp.write(hths);
            hrhs='const CanIf_HrhConfigType CanIfHrhConfigData_%s[]=\n{\n'%(channel.name);
            eol=0;
            for hrh in channel.hrhList:
                eol+=1;
                hrhs+='\t{\n'
                hrhs+='\t\t/*CanIfHrhType =*/ %s,\n'%(hrh.hohType);
                hrhs+='\t\t/*CanIfSoftwareFilterHrh =*/ %s,\n'%(TRUE(hrh.softwareFilter));
                hrhs+='\t\t/*CanIfCanControllerIdRef =*/ %s,\n'%(channel.name);
                hrhs+='\t\t/*CanIfHrhIdSymRef =*/ %s,\n'%(hrh.hohIdSymRef);
                if(eol==len(channel.hrhList)):
                    hrhs+='\t\t/*CanIf_Arc_EOL =*/ TRUE\n'
                else:
                    hrhs+='\t\t/*CanIf_Arc_EOL =*/ FALSE\n'
                hrhs+='\t},\n'
            hrhs+='};\n\n'
            fp.write(hrhs);
        #CanIf Channel Hoh
        chs='const CanIf_InitHohConfigType CanIfHohConfigData[] =\n{\n'
        eol=0;
        for channel in self.cfg.channelList:
            eol+=1;
            chs+='\t{\n';
            chs+='\t\t/*CanConfigSet =*/ &Can_ConfigSetData,\n';
            chs+='\t\t/*CanIfHrhConfig =*/ CanIfHrhConfigData_%s,\n'%(channel.name);
            chs+='\t\t/*CanIfHthConfig =*/ CanIfHthConfigData_%s,\n'%(channel.name);
            if(eol==len(self.cfg.channelList)):
                chs+='\t\t/*CanIf_Arc_EOL =*/ TRUE\n';
            else:
                chs+='\t\t/*CanIf_Arc_EOL =*/ FALSE\n';
            chs+='\t},\n'; 
        chs+='};\n\n';
        fp.write(chs);
        txpdus='const CanIf_TxPduConfigType CanIfTxPduConfigData[] = \n{\n';
        TX_PDU_CNT=0;
        for channel in self.cfg.channelList:
            index=0;
            for hth in channel.hthList:
                for pdu in hth.pduList:
                    TX_PDU_CNT+=1;
                    txpdus+='\t{\n';
                    txpdus+='\t\t/*CanIfTxPduId =*/ %s_%s,\n'%(
                            self.getPduIdPrefix(pdu), pdu.name);
                    txpdus+='\t\t/*CanIfCanTxPduIdCanId =*/ %s,\n'%(pdu.canId);
                    txpdus+='\t\t/*CanIfCanTxPduIdDlc =*/ %s,\n'%(pdu.dlc);
                    txpdus+='\t\t/*CanIfCanTxPduType =*/ %s,\n'%(pdu.canType);
                    txpdus+='#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )\n\t\t/*CanIfReadTxPduNotifyStatus =*/ FALSE, \n#endif\n';
                    txpdus+='\t\t/*CanIfTxPduIdCanIdType =*/ %s,\n'%(pdu.canIdType);
                    txpdus+='\t\t/*CanIfUserTxConfirmation =*/ %s,\n'%(pdu.confirmation);
                    txpdus+='\t\t/*CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_%s[%s],\n'%(channel.name, index);
                    txpdus+='\t\t/*PduIdRef =*/ NULL\n';
                    txpdus+='\t},\n';
                index+=1;
        txpdus+='};\n\n'
        fp.write(txpdus);
        rxpdus='const CanIf_RxPduConfigType CanIfRxPduConfigData[] = \n{\n';
        RX_PDU_CNT=0;
        for channel in self.cfg.channelList:
            index=0;
            for hrh in channel.hrhList:
                for pdu in hrh.pduList:
                    RX_PDU_CNT+=1;
                    rxpdus+='\t{\n';
                    rxpdus+='\t\t/*CanIfCanRxPduId =*/ %s_%s,\n'%(
                            self.getPduIdPrefix(pdu), pdu.name);
                    rxpdus+='\t\t/*CanIfCanRxPduCanId =*/ %s,\n'%(pdu.canId);
                    rxpdus+='\t\t/*CanIfCanRxPduDlc =*/ %s,\n'%(pdu.dlc);
                    rxpdus+='#if ( CANIF_CANPDUID_READDATA_API == STD_ON )\n\t\t/*CanIfReadRxPduData =*/ TRUE,\n#endif\n'
                    rxpdus+='#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )\n\t\t/*CanIfReadRxPduNotifyStatus =*/ TRUE, \n#endif\n';
                    rxpdus+='\t\t/*CanIfRxPduIdCanIdType =*/ %s,\n'%(pdu.canIdType);
                    rxpdus+='\t\t/*CanIfRxUserType =*/ CANIF_USER_TYPE_%s,\n'%(pdu.indicationType);
                    if(pdu.indicationType=='CAN_SPECIAL'):
                        rxpdus+='\t\t/*CanIfUserRxIndication =*/ %s,\n'%(pdu.userIndication);
                    else:
                        rxpdus+='\t\t/*CanIfUserRxIndication =*/ NULL,\n';
                    rxpdus+='\t\t/*CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_%s[%s],\n'%(channel.name, index);
                    rxpdus+='\t\t/*PduIdRef =*/ NULL,\n';
                    rxpdus+='\t\t/*CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,\n';
                    rxpdus+='\t\t/*CanIfCanRxPduCanIdMask =*/ %s\n'%(pdu.canIdMask);
                    #if(pdu.canIdType=='CANIF_CAN_ID_TYPE_11'):
                    #    rxpdus+='\t\t/*CanIfCanRxPduCanIdMask =*/ 0x7FF\n';
                    #else:
                    #    rxpdus+='\t\t/*CanIfCanRxPduCanIdMask =*/ 0x1FFFFFFF\n';#29
                    rxpdus+='\t},\n';
                index+=1;
        rxpdus+='};\n\n'
        fp.write(rxpdus);
        #InitConfig
        fp.write('// This container contains the init parameters of the CAN\n');
        fp.write('// Multiplicity 1/*/**\n');
        fp.write('const CanIf_InitConfigType CanIfInitConfig =\n');
        fp.write('{\n');
        fp.write('\t/*CanIfConfigSet =*/ 0, // Not used \n'); 
        fp.write('\t/*CanIfNumberOfCanRxPduIds =*/ %s,\n'%(RX_PDU_CNT));
        fp.write('\t/*CanIfNumberOfCanTXPduIds =*/ %s,\n'%(TX_PDU_CNT));
        fp.write('\t/*CanIfNumberOfDynamicCanTXPduIds =*/ 0, // Not used\n');
        fp.write('\t// Containers\n');
        fp.write('\t/*CanIfHohConfigPtr =*/ CanIfHohConfigData,\n');
        fp.write('\t/*CanIfRxPduConfigPtr =*/ CanIfRxPduConfigData,\n');
        fp.write('\t/*CanIfTxPduConfigPtr =*/ CanIfTxPduConfigData,\n');
        fp.write('};\n');
        fp.write('// This container includes all necessary configuration sub-containers\n');
        fp.write('// according the CAN Interface configuration structure\n');
        fp.write('const CanIf_ConfigType CanIf_Config =\n');
        fp.write('{\n');
        fp.write('\t/*ControllerConfig =*/ CanIfControllerConfig,\n');
        fp.write('\t/*DispatchConfig =*/ &CanIfDispatchConfig,\n');
        fp.write('\t/*InitConfig =*/ &CanIfInitConfig,\n');
        fp.write('\t/*TransceiverConfig =*/ NULL, // Not used\n');
        fp.write('\t/*Arc_ChannelToControllerMap =*/ CanIf_Arc_ChannelToControllerMap,\n');  
        fp.write('\t/*Arc_ChannelDefaultConfIndex =*/ CanIf_Arc_ChannelDefaultConfIndex,\n');
        fp.write('};\n');
        fp.close();

    def getPduIdPrefix(self, pdu):
        if(pdu.type == 'txPdu'):
            if(pdu.confirmation == 'PduR_CanIfTxConfirmation'):
                return 'PDUR';
            elif(pdu.confirmation == 'CanTp_TxConfirmation'):
                return 'CANTP';
        elif(pdu.type == 'rxPdu'):
            if(pdu.indicationType == 'CAN_NM'):
                return 'CANNM';
            elif(pdu.indicationType == 'CAN_TP'):
                return 'CANTP';
            elif(pdu.indicationType == 'CAN_PDUR'):
                return 'PDUR';
        return 'CANIF';
