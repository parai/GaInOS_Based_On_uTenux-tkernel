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

import xml.etree.ElementTree as ET
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
import sys
from GaInOsCfg import *

def bool(s):
    if(s=='True'):
        return True;
    else:
        return False;

def gnewArxml(arxml):
    """Global Function:new an arxml"""
    fp = open(arxml, 'w');
    fp.write('<?xml version="1.0" encoding="utf-8"?>\n\n');
    fp.write('<GaInOsCfg></GaInOsCfg>\n\n');
    fp.close();
    
class LoadArxml():
    def __init__(self,cfg,arxml):
        root = self.tryOpen(arxml);
        self.doParse(cfg, root);

    def tryOpen(self, arxml):
        """try open arxml,if failed create a new one."""
        try:  
            root = ET.parse(arxml).getroot();
        except Exception, e: 
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Invalid Configure File,Will Generate a new one!').exec_();
            gnewArxml(arxml);
            root = self.arxml= ET.parse(arxml).getroot();
        return root;

    def doParse(self, cfg, root):
        self.doParseTask(cfg, root.find('TaskList'));
        self.doParseResource(cfg, root.find('ResourceList'));
        self.doParseAlarm(cfg, root.find('AlarmList'));

    def doParseTask(self, cfg, list):
        del cfg.taskList;
        cfg.taskList=[];
        for node in list:
            obj=Task(node.attrib['name'],   \
                    int(node.attrib['prio']),   \
                    int(node.attrib['stksz']));
            obj.autostart=bool(node.attrib['autostart']);
            for nd in node.find('EventList'):
                ent=Event(nd.attrib['name'], nd.attrib['mask']);
                obj.eventList.append(ent);
            cfg.taskList.append(obj);

    def doParseResource(self, cfg, list):
        del cfg.resourceList;
        cfg.resourceList=[];
        for node in list:
            obj=Resource(node.attrib['name'],int(node.attrib['ceilprio']));
            cfg.resourceList.append(obj);

    def doParseAlarm(self, cfg, list):
        del cfg.alarmList;
        cfg.alarmList=[];
        for node in list:
            obj=Alarm(node.attrib['name']);
            obj.type=node.attrib['type'];
            obj.task=node.attrib['task'];
            obj.event=node.attrib['event'];
            cfg.alarmList.append(obj);
