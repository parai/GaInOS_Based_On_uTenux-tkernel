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

class ComGeneral():
    def __init__(self):
        self.DevErrorDetection = False;

    def save(self, fp):
        fp.write('<ComGeneral>\n');
        fp.write('<DevErrorDetection value="%s"></DevErrorDetection>\n'%(self.DevErrorDetection));
        fp.write('</ComGeneral>\n');

    def parse(self, node):
        self.DevErrorDetection=bool(node.find('DevErrorDetection').attrib['value']);

class ComIPduGroup():
    def __init__(self, name):
        self.name = name;

    def save(self, fp):
        fp.write('<ComIPduGroup name="%s"></ComIPduGroup>\n'%(self.name));

    def parse(self, node):
        self.name = node.attrib['name'];

class ComSignal():
    def __init__(self, name):
        self.name = name;
        self.isSignalGroup=False;
        self.ComBitPosition = 0;#应该是8的整数倍
        self.ComBitSize = 8;
        self.ComErrorNotification = 'NULL';
        self.ComFirstTimeoutFactor = 10;
        self.ComNotification = 'NULL';
        self.ComRxDataTimeoutAction = 'NONE';
        self.ComSignalEndianess = 'COM_BIG_ENDIAN';
        self.ComSignalInitValue = '0x00';
        self.ComSignalType = 'UINT8';
        self.ComTimeoutFactor =10;
        self.ComTimeoutNotification = 'NULL';
        self.ComTransferProperty = 'TRIGGERED';
        self.ComUpdateBitPosition = 0;
        self.ComSignalArcUseUpdateBit = False;

class ComGroupSignal():
    def __init__(self, name):
        self.name = name;
        self.ComSignalType = 'UINT8';
        self.ComSignalEndianess = 'COM_BIG_ENDIAN';
        self.ComBitPosition = 0;#应该是8的整数倍
        self.ComBitSize = 8;
        self.ComSignalInitValue = '0x00';

class ComSignalGroup():
    def __init__(self, name):
        self.name = name;
        self.isSignalGroup=True;
        self.ComTransferProperty = 'TRIGGERED';
        self.ComUpdateBitPosition = 0;
        self.ComSignalArcUseUpdateBit = False;
        self.ComBitPosition = 0;#应该是8的整数倍
        self.ComBitSize = 8;
        self.ComFirstTimeoutFactor = 10;
        self.ComTimeoutFactor = 10;
        self.ComNotification = 'NULL';
        self.ComTimeoutNotification = 'NULL';
        self.groupSignalList = [];
    
class ComIPdu():
    def __init__(self, name):
        self.name = name;
        self.ComIPduCallout = 'NULL';
        self.ArcIPduOutgoingId ='';
        self.ComIPduSignalProcessing ='DEFERRED';
        #self.ComIPduSize = 64;#should calculate it
        self.ComIPduDirection = 'SEND';
        self.ComIPduGroupRef = '';
        self.ComTxIPduMinimumDelayFactor = 0;
        self.ComTxIPduUnusedAreasDefault = 0;
        self.ComTxModeMode = 'PERIODIC';
        self.ComTxModeNumberOfRepetitions = 0;
        self.ComTxModeRepetitionPeriodFactor = 10;
        self.ComTxModeTimeOffsetFactor = 20;
        self.ComTxModeTimePeriodFactor = 10;
        self.signalList = [];
        self.signalGroupList = [];
    
    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib += 'ComIPduCallout="%s" '%(self.ComIPduCallout);
        attrib += 'ArcIPduOutgoingId="%s" '%(self.ArcIPduOutgoingId);
        attrib += 'ComIPduSignalProcessing="%s" '%(self.ComIPduSignalProcessing);
        attrib += 'ComIPduDirection="%s" '%(self.ComIPduDirection);
        attrib += 'ComIPduGroupRef="%s" '%(self.ComIPduGroupRef);
        attrib += 'ComTxIPduMinimumDelayFactor="%s" '%(self.ComTxIPduMinimumDelayFactor);
        attrib += 'ComTxIPduUnusedAreasDefault="%s" '%(self.ComTxIPduUnusedAreasDefault);
        attrib += 'ComTxModeMode="%s" '%(self.ComTxModeMode);
        attrib += 'ComTxModeNumberOfRepetitions="%s" '%(self.ComTxModeNumberOfRepetitions);
        attrib += 'ComTxModeRepetitionPeriodFactor="%s" '%(self.ComTxModeRepetitionPeriodFactor);
        attrib += 'ComTxModeTimeOffsetFactor="%s" '%(self.ComTxModeTimeOffsetFactor);
        attrib += 'ComTxModeTimePeriodFactor="%s" '%(self.ComTxModeTimePeriodFactor);
        fp.write('<ComIPdu %s></ComIPdu>\n'%(attrib));

    def parse(self, node):
        self.name = node.attrib['name'];
        self.ComIPduCallout = node.attrib['ComIPduCallout'];
        self.ArcIPduOutgoingId = node.attrib['ArcIPduOutgoingId'];
        self.ComIPduSignalProcessing = node.attrib['ComIPduSignalProcessing'];
        self.ComIPduDirection = node.attrib['ComIPduDirection'];
        self.ComIPduGroupRef = node.attrib['ComIPduGroupRef'];
        self.ComTxIPduMinimumDelayFactor = int(node.attrib['ComTxIPduMinimumDelayFactor']);
        self.ComTxIPduUnusedAreasDefault = int(node.attrib['ComTxIPduUnusedAreasDefault']);
        self.ComTxModeMode = node.attrib['ComTxModeMode'];
        self.ComTxModeNumberOfRepetitions = int(node.attrib['ComTxModeNumberOfRepetitions']);
        self.ComTxModeRepetitionPeriodFactor = int(node.attrib['ComTxModeRepetitionPeriodFactor']);
        self.ComTxModeTimeOffsetFactor = int(node.attrib['ComTxModeTimeOffsetFactor']);
        self.ComTxModeTimePeriodFactor = int(node.attrib['ComTxModeTimePeriodFactor']);

class ComConfig():
    def __init__(self):
        self.General=ComGeneral();
        self.IPduGroupList = [];
        self.IPduList = [];

from Com_Dlg import *
class ComObj():
    def __init__(self):
        self.cfg=ComConfig();
        print "init Com Object"

    def toString(self):
        str='  Double Clicked to Start to Configure the Com!\n';
        return str;

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def show(self, cfg):
        depinfo=[];
        obj=self.findObj(cfg.arobjList, 'EcuC');
        if(obj==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(obj.arobj);
        dlg=Com_Dlg(self.cfg, depinfo);
        dlg.exec_();
  
    def saveIPduGroup(self, fp):
        fp.write('<ComIPduGroupList>\n');
        for obj in self.cfg.IPduGroupList:
            obj.save(fp);
        fp.write('</ComIPduGroupList>\n');

    def saveIPdu(self, fp):
        fp.write('<ComIPduList>\n');
        for obj in self.cfg.IPduList:
            obj.save(fp);
        fp.write('</ComIPduList>\n');
    
    def save(self, fp):
        """保存配置信息"""
        self.cfg.General.save(fp);
        self.saveIPduGroup(fp);
        self.saveIPdu(fp);
    
    def doParseIPduGroup(self, list):
        for node in list:
            obj = ComIPduGroup('');
            obj.parse(node);
            self.cfg.IPduGroupList.append(obj);

    def doParseIPdu(self, list):
        for node in list:
            obj = ComIPdu('');
            obj.parse(node);
            self.cfg.IPduList.append(obj);
    
    def doParse(self, arxml):
        self.cfg.General.parse(arxml.find('ComGeneral'));
        self.doParseIPduGroup(arxml.find('ComIPduGroupList'));
        self.doParseIPdu(arxml.find('ComIPduList'));

    def backup(self, file):
        tm=localtime(time());
        file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
        shutil.copy(file, file2+'.bak');

    def codeGen(self, path):
        return;
        path1=path+'/autosar/comstack/config/Com';
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
            os.mkdir(path+'/autosar/comstack/config/Com');
        except:
            print "nothing serious!file already exists."
        self.codeGenH(path1);

    def codeGenH(self, path):
        file=path+'/Com_Cfg.h';
        if os.path.isfile(file):
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#ifndef COM_CFG_H_\n#define COM_CFG_H_\n\n');
        fp.close();
