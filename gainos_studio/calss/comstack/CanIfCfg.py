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
class CanIfGeneral():
    def __init__(self):
        self.DevErrorDetection=False;
        self.VersionInfoApi = False;
        self.DlcCheck=True;
        self.RuntimePduConfig=False;
        self.BusoffNotification='CanIf_User_BusoffNotification';
        self.ErrorNotification='CanIf_User_ErrorNotification';
        self.SoftwareFilterType='CANIF_SOFTFILTER_TYPE_MASK';
class CanIfPdu():
    def __init__(self, name):
        self.name=name;
  
class CanIfHth():
    def __init__(self, name):
        self.name=name;
        self.type='hth';
        self.pduList=[];

class CanIfHrh():
    def __init__(self, name):
        self.name=name;
        self.type='hrh';
        self.pduList=[];

class CanIfChannel():
    def __init__(self, name):
        self.name=name;
        self.hthList=[];
        self.hrhList=[];

class CanIfConfig():
    def __init__(self):
        self.General=CanIfGeneral();
        self.channelList=[];

from CanIf_Dlg import *
class CanIfObj():
    def __init__(self):
        self.cfg=CanIfConfig();
        print "init CanIf Object"

    def toString(self):
        str='  Double Clicked to Start to Configure the Can Interface!\n';
        return str;

    def show(self):
        dlg=CanIf_Dlg(self.cfg);
        dlg.exec_();
    
    def save(self, fp):
        """保存配置信息"""
        return;
        
    def doParse(self, arxml):
        return;
