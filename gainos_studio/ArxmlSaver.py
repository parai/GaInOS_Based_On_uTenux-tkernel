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

class ArxmlSaver():
    def __init__(self, cfg, arxml):
        fp=open(arxml, 'w');
        fp.write('<?xml version="1.0" encoding="utf-8"?>\n\n');
        fp.write('<GaInOsCfg>\n');
        self.saveTask(fp, cfg.taskList);
        self.saveResource(fp, cfg.resourceList);
        self.saveAlarm(fp, cfg.alarmList);
        fp.write('</GaInOsCfg>\n');
        fp.close();

    def saveTask(self, fp, list):
        fp.write('<TaskList>\n');
        for obj in list:
            fp.write('<Task name=\'%s\' prio=\'%s\' stksz=\'%s\' autostart=\'%s\'>\n'%(
                    obj.name, obj.prio, obj.stksz, obj.autostart));
            fp.write('<EventList>\n');
            for ent in obj.eventList:
                fp.write('<Event name=\'%s\' mask=\'%s\'></Event>\n'%(ent.name, ent.mask));
            fp.write('</EventList>\n');
            fp.write('</Task>\n');
        fp.write('</TaskList>\n');

    def saveAlarm(self, fp, list):
        fp.write('<AlarmList>\n');
        for obj in list:
            fp.write('<Alarm name=\'%s\' type=\'%s\' task=\'%s\' event=\'%s\'></Alarm>\n'%(
                    obj.name, obj.type, obj.task, obj.event));
        fp.write('</AlarmList>\n');

    def saveResource(self, fp, list):
        fp.write('<ResourceList>\n');
        for obj in list:
            fp.write('<Resource name=\'%s\' ceilprio=\'%s\'></Resource>\n'%(obj.name, obj.ceilprio));
        fp.write('</ResourceList>\n');
