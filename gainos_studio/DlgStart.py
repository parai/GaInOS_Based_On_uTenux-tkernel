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

from Ui_DlgStart import Ui_DlgStart
import os
class DlgStart(QDialog, Ui_DlgStart):
    """
    Class documentation goes here.
    """
    def __init__(self, root, parent = None):
        """
        Constructor
        """
        self.proj=None;
        self.result=False;
        QDialog.__init__(self, parent);
        self.setupUi(self);
        self.listProject(root);
    
    def listProject(self, root):
        """如果其是一个有效的工程，即存在kernel/osek/src目录"""
        for dr in os.listdir(root+'/'):         
            if os.path.isdir(root+'/'+dr):
                if(dr != '.metadata'):
                    if(os.path.isdir(root+'/'+dr+'/kernel/osek/src')):
                        self.cmbxProj.addItem('%s'%(dr));

    @pyqtSignature("QString")
    def on_cmbxProj_currentIndexChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        self.proj=p0;
    
    @pyqtSignature("")
    def on_btnYes_clicked(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        self.result=True;
        self.close();
    
    @pyqtSignature("")
    def on_btnNo_clicked(self):
        self.close();
