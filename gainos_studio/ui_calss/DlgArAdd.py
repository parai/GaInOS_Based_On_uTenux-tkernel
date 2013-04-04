# -*- coding: utf-8 -*-

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

from Ui_DlgArAdd import Ui_DlgArAdd
ArComp=['Adc', 'Can','CanIf','CanNm', 'CanTp', 'CanSm', 'Com', 
        'Dio', 'Eep', 'EcuC', 'Fls', 'Gpt', 'Icu', 'Pwm', 'Port', 'Mcu', 
        'PduR', 'Spi', 'Wdg', 'WdgIf']
class DlgArAdd(QDialog, Ui_DlgArAdd):
    """
    Class documentation goes here.
    """
    def __init__(self, list, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent);
        """list是Autosar 组建链表，其是一个特殊的容器"""
        self.result=False;
        self.comp='';
        self.setupUi(self);
        self.initGUI(list);

    def isArInList(self, ar, list):
        for obj in list:
            if(obj.name==ar):
                return True;
        return False;
    
    def initGUI(self, list):
        for ar in ArComp:
            if(self.isArInList(ar, list)!=True):
                item=QTreeWidgetItem(self.trArCom,QStringList(ar));
                self.trArCom.insertTopLevelItem(0, item);
        self.trArCom.sortColumn();
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trArCom_itemClicked(self, item, column):
        self.comp=item.text(0);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trArCom_itemDoubleClicked(self, item, column):
        self.comp=item.text(0);
        self.result=True;
        self.close();
    
    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        if(self.comp != ''):
            self.result=True;
        else:
            self.result=False;
        self.close();
    
    @pyqtSignature("")
    def on_btnCancel_clicked(self):
        self.close();
