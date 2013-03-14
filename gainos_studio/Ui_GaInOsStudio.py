# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'D:\usr\com\gainos_studio\GaInOsStudio.ui'
#
# Created: Wed Mar 13 23:29:51 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_wMainClass(object):
    def setupUi(self, wMainClass):
        wMainClass.setObjectName(_fromUtf8("wMainClass"))
        wMainClass.resize(1040, 617)
        wMainClass.setStyleSheet(_fromUtf8("font: 12pt \"Monospace\";"))
        self.centralwidget = QtGui.QWidget(wMainClass)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.groupBox_2 = QtGui.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(20, 60, 1001, 521))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.trGaInOsCfgList = QtGui.QTreeWidget(self.groupBox_2)
        self.trGaInOsCfgList.setGeometry(QtCore.QRect(20, 30, 271, 471))
        self.trGaInOsCfgList.setObjectName(_fromUtf8("trGaInOsCfgList"))
        item_0 = QtGui.QTreeWidgetItem(self.trGaInOsCfgList)
        item_0 = QtGui.QTreeWidgetItem(self.trGaInOsCfgList)
        item_0 = QtGui.QTreeWidgetItem(self.trGaInOsCfgList)
        self.tblGaInOsCfg = QtGui.QTabWidget(self.groupBox_2)
        self.tblGaInOsCfg.setGeometry(QtCore.QRect(510, 20, 481, 311))
        self.tblGaInOsCfg.setObjectName(_fromUtf8("tblGaInOsCfg"))
        self.tabTask = QtGui.QWidget()
        self.tabTask.setObjectName(_fromUtf8("tabTask"))
        self.layoutWidget = QtGui.QWidget(self.tabTask)
        self.layoutWidget.setGeometry(QtCore.QRect(20, 20, 431, 188))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.gridLayout = QtGui.QGridLayout(self.layoutWidget)
        self.gridLayout.setMargin(0)
        self.gridLayout.setObjectName(_fromUtf8("gridLayout"))
        self.label_5 = QtGui.QLabel(self.layoutWidget)
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.gridLayout.addWidget(self.label_5, 0, 0, 1, 1)
        self.leTskName = QtGui.QLineEdit(self.layoutWidget)
        self.leTskName.setObjectName(_fromUtf8("leTskName"))
        self.gridLayout.addWidget(self.leTskName, 0, 1, 1, 4)
        self.label_8 = QtGui.QLabel(self.layoutWidget)
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.gridLayout.addWidget(self.label_8, 1, 0, 1, 2)
        self.spbxTskStkSize = QtGui.QSpinBox(self.layoutWidget)
        self.spbxTskStkSize.setMinimumSize(QtCore.QSize(101, 0))
        self.spbxTskStkSize.setMinimum(64)
        self.spbxTskStkSize.setMaximum(10240000)
        self.spbxTskStkSize.setObjectName(_fromUtf8("spbxTskStkSize"))
        self.gridLayout.addWidget(self.spbxTskStkSize, 1, 2, 1, 3)
        self.label_6 = QtGui.QLabel(self.layoutWidget)
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.gridLayout.addWidget(self.label_6, 2, 0, 1, 1)
        self.cmbxTskType = QtGui.QComboBox(self.layoutWidget)
        self.cmbxTskType.setMinimumSize(QtCore.QSize(111, 0))
        self.cmbxTskType.setObjectName(_fromUtf8("cmbxTskType"))
        self.cmbxTskType.addItem(_fromUtf8(""))
        self.cmbxTskType.addItem(_fromUtf8(""))
        self.gridLayout.addWidget(self.cmbxTskType, 2, 1, 1, 3)
        self.label_7 = QtGui.QLabel(self.layoutWidget)
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.gridLayout.addWidget(self.label_7, 3, 0, 1, 2)
        self.spbxTskPrio = QtGui.QSpinBox(self.layoutWidget)
        self.spbxTskPrio.setMinimumSize(QtCore.QSize(101, 0))
        self.spbxTskPrio.setObjectName(_fromUtf8("spbxTskPrio"))
        self.gridLayout.addWidget(self.spbxTskPrio, 3, 3, 1, 2)
        self.label_10 = QtGui.QLabel(self.layoutWidget)
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.gridLayout.addWidget(self.label_10, 4, 0, 1, 4)
        self.spbxTskMaxActivateCount = QtGui.QSpinBox(self.layoutWidget)
        self.spbxTskMaxActivateCount.setMinimumSize(QtCore.QSize(91, 0))
        self.spbxTskMaxActivateCount.setObjectName(_fromUtf8("spbxTskMaxActivateCount"))
        self.gridLayout.addWidget(self.spbxTskMaxActivateCount, 4, 4, 1, 1)
        self.cbxTskAutoStart = QtGui.QCheckBox(self.layoutWidget)
        self.cbxTskAutoStart.setObjectName(_fromUtf8("cbxTskAutoStart"))
        self.gridLayout.addWidget(self.cbxTskAutoStart, 5, 0, 1, 3)
        self.cbxTskPreemtable = QtGui.QCheckBox(self.layoutWidget)
        self.cbxTskPreemtable.setObjectName(_fromUtf8("cbxTskPreemtable"))
        self.gridLayout.addWidget(self.cbxTskPreemtable, 6, 0, 1, 3)
        self.tblGaInOsCfg.addTab(self.tabTask, _fromUtf8(""))
        self.tabRes = QtGui.QWidget()
        self.tabRes.setObjectName(_fromUtf8("tabRes"))
        self.layoutWidget1 = QtGui.QWidget(self.tabRes)
        self.layoutWidget1.setGeometry(QtCore.QRect(20, 20, 374, 66))
        self.layoutWidget1.setObjectName(_fromUtf8("layoutWidget1"))
        self.gridLayout_2 = QtGui.QGridLayout(self.layoutWidget1)
        self.gridLayout_2.setMargin(0)
        self.gridLayout_2.setObjectName(_fromUtf8("gridLayout_2"))
        self.label_11 = QtGui.QLabel(self.layoutWidget1)
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.gridLayout_2.addWidget(self.label_11, 0, 0, 1, 1)
        self.leResName = QtGui.QLineEdit(self.layoutWidget1)
        self.leResName.setMinimumSize(QtCore.QSize(231, 0))
        self.leResName.setObjectName(_fromUtf8("leResName"))
        self.gridLayout_2.addWidget(self.leResName, 0, 1, 1, 2)
        self.label_12 = QtGui.QLabel(self.layoutWidget1)
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.gridLayout_2.addWidget(self.label_12, 1, 0, 1, 2)
        self.spbxResCeilPrio = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxResCeilPrio.setMinimumSize(QtCore.QSize(91, 0))
        self.spbxResCeilPrio.setObjectName(_fromUtf8("spbxResCeilPrio"))
        self.gridLayout_2.addWidget(self.spbxResCeilPrio, 1, 2, 1, 1)
        self.tblGaInOsCfg.addTab(self.tabRes, _fromUtf8(""))
        self.tabCnt = QtGui.QWidget()
        self.tabCnt.setObjectName(_fromUtf8("tabCnt"))
        self.layoutWidget2 = QtGui.QWidget(self.tabCnt)
        self.layoutWidget2.setGeometry(QtCore.QRect(20, 30, 420, 136))
        self.layoutWidget2.setObjectName(_fromUtf8("layoutWidget2"))
        self.gridLayout_4 = QtGui.QGridLayout(self.layoutWidget2)
        self.gridLayout_4.setMargin(0)
        self.gridLayout_4.setObjectName(_fromUtf8("gridLayout_4"))
        self.label_15 = QtGui.QLabel(self.layoutWidget2)
        self.label_15.setObjectName(_fromUtf8("label_15"))
        self.gridLayout_4.addWidget(self.label_15, 0, 0, 1, 1)
        self.leCntName = QtGui.QLineEdit(self.layoutWidget2)
        self.leCntName.setMinimumSize(QtCore.QSize(231, 0))
        self.leCntName.setObjectName(_fromUtf8("leCntName"))
        self.gridLayout_4.addWidget(self.leCntName, 0, 1, 1, 3)
        self.label_16 = QtGui.QLabel(self.layoutWidget2)
        self.label_16.setObjectName(_fromUtf8("label_16"))
        self.gridLayout_4.addWidget(self.label_16, 1, 0, 1, 2)
        self.spbxCntMaxAllowedValue = QtGui.QSpinBox(self.layoutWidget2)
        self.spbxCntMaxAllowedValue.setMinimumSize(QtCore.QSize(91, 0))
        self.spbxCntMaxAllowedValue.setMinimum(1)
        self.spbxCntMaxAllowedValue.setMaximum(65535)
        self.spbxCntMaxAllowedValue.setObjectName(_fromUtf8("spbxCntMaxAllowedValue"))
        self.gridLayout_4.addWidget(self.spbxCntMaxAllowedValue, 1, 2, 1, 2)
        self.label_17 = QtGui.QLabel(self.layoutWidget2)
        self.label_17.setObjectName(_fromUtf8("label_17"))
        self.gridLayout_4.addWidget(self.label_17, 2, 0, 1, 2)
        self.spbxCntTickBase = QtGui.QSpinBox(self.layoutWidget2)
        self.spbxCntTickBase.setMinimumSize(QtCore.QSize(91, 0))
        self.spbxCntTickBase.setMinimum(1)
        self.spbxCntTickBase.setMaximum(65535)
        self.spbxCntTickBase.setObjectName(_fromUtf8("spbxCntTickBase"))
        self.gridLayout_4.addWidget(self.spbxCntTickBase, 2, 2, 1, 2)
        self.label_18 = QtGui.QLabel(self.layoutWidget2)
        self.label_18.setObjectName(_fromUtf8("label_18"))
        self.gridLayout_4.addWidget(self.label_18, 3, 0, 1, 3)
        self.spbxCntMinCycle = QtGui.QSpinBox(self.layoutWidget2)
        self.spbxCntMinCycle.setMinimumSize(QtCore.QSize(91, 0))
        self.spbxCntMinCycle.setMinimum(1)
        self.spbxCntMinCycle.setMaximum(65535)
        self.spbxCntMinCycle.setObjectName(_fromUtf8("spbxCntMinCycle"))
        self.gridLayout_4.addWidget(self.spbxCntMinCycle, 3, 3, 1, 1)
        self.tblGaInOsCfg.addTab(self.tabCnt, _fromUtf8(""))
        self.tabAlm = QtGui.QWidget()
        self.tabAlm.setObjectName(_fromUtf8("tabAlm"))
        self.widget = QtGui.QWidget(self.tabAlm)
        self.widget.setGeometry(QtCore.QRect(22, 20, 431, 136))
        self.widget.setObjectName(_fromUtf8("widget"))
        self.gridLayout_3 = QtGui.QGridLayout(self.widget)
        self.gridLayout_3.setMargin(0)
        self.gridLayout_3.setObjectName(_fromUtf8("gridLayout_3"))
        self.label_19 = QtGui.QLabel(self.widget)
        self.label_19.setEnabled(True)
        self.label_19.setFrameShape(QtGui.QFrame.NoFrame)
        self.label_19.setObjectName(_fromUtf8("label_19"))
        self.gridLayout_3.addWidget(self.label_19, 0, 0, 1, 1)
        self.leAlarmName = QtGui.QLineEdit(self.widget)
        self.leAlarmName.setEnabled(True)
        self.leAlarmName.setMinimumSize(QtCore.QSize(231, 0))
        self.leAlarmName.setObjectName(_fromUtf8("leAlarmName"))
        self.gridLayout_3.addWidget(self.leAlarmName, 0, 1, 1, 2)
        self.label_24 = QtGui.QLabel(self.widget)
        self.label_24.setObjectName(_fromUtf8("label_24"))
        self.gridLayout_3.addWidget(self.label_24, 1, 0, 1, 1)
        self.cmbxAlarmOwner = QtGui.QComboBox(self.widget)
        self.cmbxAlarmOwner.setMinimumSize(QtCore.QSize(231, 0))
        self.cmbxAlarmOwner.setObjectName(_fromUtf8("cmbxAlarmOwner"))
        self.cmbxAlarmOwner.addItem(_fromUtf8(""))
        self.gridLayout_3.addWidget(self.cmbxAlarmOwner, 1, 1, 1, 2)
        self.label_20 = QtGui.QLabel(self.widget)
        self.label_20.setObjectName(_fromUtf8("label_20"))
        self.gridLayout_3.addWidget(self.label_20, 2, 0, 1, 1)
        self.cmbxAlarmType = QtGui.QComboBox(self.widget)
        self.cmbxAlarmType.setMinimumSize(QtCore.QSize(231, 0))
        self.cmbxAlarmType.setObjectName(_fromUtf8("cmbxAlarmType"))
        self.cmbxAlarmType.addItem(_fromUtf8(""))
        self.cmbxAlarmType.addItem(_fromUtf8(""))
        self.cmbxAlarmType.addItem(_fromUtf8(""))
        self.gridLayout_3.addWidget(self.cmbxAlarmType, 2, 1, 1, 2)
        self.lblAlarmTask = QtGui.QLabel(self.widget)
        self.lblAlarmTask.setObjectName(_fromUtf8("lblAlarmTask"))
        self.gridLayout_3.addWidget(self.lblAlarmTask, 3, 0, 1, 2)
        self.cmbxAlarmTask = QtGui.QComboBox(self.widget)
        self.cmbxAlarmTask.setMinimumSize(QtCore.QSize(231, 0))
        self.cmbxAlarmTask.setObjectName(_fromUtf8("cmbxAlarmTask"))
        self.gridLayout_3.addWidget(self.cmbxAlarmTask, 3, 2, 1, 1)
        self.label_23 = QtGui.QLabel(self.widget)
        self.label_23.setObjectName(_fromUtf8("label_23"))
        self.gridLayout_3.addWidget(self.label_23, 4, 0, 1, 2)
        self.cmbxAlarmEvent = QtGui.QComboBox(self.widget)
        self.cmbxAlarmEvent.setMinimumSize(QtCore.QSize(231, 0))
        self.cmbxAlarmEvent.setObjectName(_fromUtf8("cmbxAlarmEvent"))
        self.gridLayout_3.addWidget(self.cmbxAlarmEvent, 4, 2, 1, 1)
        self.tblGaInOsCfg.addTab(self.tabAlm, _fromUtf8(""))
        self.tabEvent = QtGui.QWidget()
        self.tabEvent.setObjectName(_fromUtf8("tabEvent"))
        self.layoutWidget3 = QtGui.QWidget(self.tabEvent)
        self.layoutWidget3.setGeometry(QtCore.QRect(20, 21, 445, 66))
        self.layoutWidget3.setObjectName(_fromUtf8("layoutWidget3"))
        self.gridLayout_6 = QtGui.QGridLayout(self.layoutWidget3)
        self.gridLayout_6.setMargin(0)
        self.gridLayout_6.setObjectName(_fromUtf8("gridLayout_6"))
        self.label_25 = QtGui.QLabel(self.layoutWidget3)
        self.label_25.setObjectName(_fromUtf8("label_25"))
        self.gridLayout_6.addWidget(self.label_25, 0, 0, 1, 1)
        self.leEventName = QtGui.QLineEdit(self.layoutWidget3)
        self.leEventName.setMinimumSize(QtCore.QSize(331, 0))
        self.leEventName.setObjectName(_fromUtf8("leEventName"))
        self.gridLayout_6.addWidget(self.leEventName, 0, 1, 1, 1)
        self.label_26 = QtGui.QLabel(self.layoutWidget3)
        self.label_26.setObjectName(_fromUtf8("label_26"))
        self.gridLayout_6.addWidget(self.label_26, 1, 0, 1, 1)
        self.leEventMask = QtGui.QLineEdit(self.layoutWidget3)
        self.leEventMask.setMinimumSize(QtCore.QSize(331, 0))
        self.leEventMask.setObjectName(_fromUtf8("leEventMask"))
        self.gridLayout_6.addWidget(self.leEventMask, 1, 1, 1, 1)
        self.tblGaInOsCfg.addTab(self.tabEvent, _fromUtf8(""))
        self.layoutWidget4 = QtGui.QWidget(self.groupBox_2)
        self.layoutWidget4.setGeometry(QtCore.QRect(311, 72, 181, 171))
        self.layoutWidget4.setObjectName(_fromUtf8("layoutWidget4"))
        self.verticalLayout = QtGui.QVBoxLayout(self.layoutWidget4)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.btnAdd = QtGui.QPushButton(self.layoutWidget4)
        self.btnAdd.setObjectName(_fromUtf8("btnAdd"))
        self.verticalLayout.addWidget(self.btnAdd)
        self.btnDel = QtGui.QPushButton(self.layoutWidget4)
        self.btnDel.setObjectName(_fromUtf8("btnDel"))
        self.verticalLayout.addWidget(self.btnDel)
        self.btnCheck = QtGui.QPushButton(self.layoutWidget4)
        self.btnCheck.setObjectName(_fromUtf8("btnCheck"))
        self.verticalLayout.addWidget(self.btnCheck)
        self.btnFileSave = QtGui.QPushButton(self.layoutWidget4)
        self.btnFileSave.setObjectName(_fromUtf8("btnFileSave"))
        self.verticalLayout.addWidget(self.btnFileSave)
        self.btnGen = QtGui.QPushButton(self.layoutWidget4)
        self.btnGen.setMinimumSize(QtCore.QSize(111, 0))
        self.btnGen.setObjectName(_fromUtf8("btnGen"))
        self.verticalLayout.addWidget(self.btnGen)
        self.layoutWidget5 = QtGui.QWidget(self.centralwidget)
        self.layoutWidget5.setGeometry(QtCore.QRect(20, 10, 832, 31))
        self.layoutWidget5.setObjectName(_fromUtf8("layoutWidget5"))
        self.horizontalLayout_4 = QtGui.QHBoxLayout(self.layoutWidget5)
        self.horizontalLayout_4.setMargin(0)
        self.horizontalLayout_4.setObjectName(_fromUtf8("horizontalLayout_4"))
        self.label_22 = QtGui.QLabel(self.layoutWidget5)
        self.label_22.setObjectName(_fromUtf8("label_22"))
        self.horizontalLayout_4.addWidget(self.label_22)
        self.leFileOpened = QtGui.QLineEdit(self.layoutWidget5)
        self.leFileOpened.setMinimumSize(QtCore.QSize(521, 0))
        self.leFileOpened.setObjectName(_fromUtf8("leFileOpened"))
        self.horizontalLayout_4.addWidget(self.leFileOpened)
        self.btnFileOpen = QtGui.QPushButton(self.layoutWidget5)
        self.btnFileOpen.setObjectName(_fromUtf8("btnFileOpen"))
        self.horizontalLayout_4.addWidget(self.btnFileOpen)
        wMainClass.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(wMainClass)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1040, 22))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuGaInOS_Studio = QtGui.QMenu(self.menubar)
        self.menuGaInOS_Studio.setObjectName(_fromUtf8("menuGaInOS_Studio"))
        self.menuHelp = QtGui.QMenu(self.menubar)
        self.menuHelp.setObjectName(_fromUtf8("menuHelp"))
        wMainClass.setMenuBar(self.menubar)
        self.statusBar = QtGui.QStatusBar(wMainClass)
        self.statusBar.setObjectName(_fromUtf8("statusBar"))
        wMainClass.setStatusBar(self.statusBar)
        self.actionInfo = QtGui.QAction(wMainClass)
        self.actionInfo.setObjectName(_fromUtf8("actionInfo"))
        self.actionAbout = QtGui.QAction(wMainClass)
        self.actionAbout.setObjectName(_fromUtf8("actionAbout"))
        self.actionNew = QtGui.QAction(wMainClass)
        self.actionNew.setObjectName(_fromUtf8("actionNew"))
        self.actionOpen = QtGui.QAction(wMainClass)
        self.actionOpen.setObjectName(_fromUtf8("actionOpen"))
        self.actionOpen_Recent_Files = QtGui.QAction(wMainClass)
        self.actionOpen_Recent_Files.setObjectName(_fromUtf8("actionOpen_Recent_Files"))
        self.actionClose = QtGui.QAction(wMainClass)
        self.actionClose.setObjectName(_fromUtf8("actionClose"))
        self.actionSave = QtGui.QAction(wMainClass)
        self.actionSave.setObjectName(_fromUtf8("actionSave"))
        self.actionSave_As = QtGui.QAction(wMainClass)
        self.actionSave_As.setObjectName(_fromUtf8("actionSave_As"))
        self.actionQuit = QtGui.QAction(wMainClass)
        self.actionQuit.setObjectName(_fromUtf8("actionQuit"))
        self.menuGaInOS_Studio.addAction(self.actionOpen)
        self.menuGaInOS_Studio.addAction(self.actionNew)
        self.menuGaInOS_Studio.addAction(self.actionOpen_Recent_Files)
        self.menuGaInOS_Studio.addSeparator()
        self.menuGaInOS_Studio.addAction(self.actionClose)
        self.menuGaInOS_Studio.addSeparator()
        self.menuGaInOS_Studio.addAction(self.actionSave)
        self.menuGaInOS_Studio.addAction(self.actionSave_As)
        self.menuGaInOS_Studio.addSeparator()
        self.menuGaInOS_Studio.addAction(self.actionQuit)
        self.menuHelp.addAction(self.actionInfo)
        self.menuHelp.addAction(self.actionAbout)
        self.menubar.addAction(self.menuGaInOS_Studio.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())

        self.retranslateUi(wMainClass)
        self.tblGaInOsCfg.setCurrentIndex(0)
        self.cmbxTskType.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(wMainClass)

    def retranslateUi(self, wMainClass):
        wMainClass.setWindowTitle(QtGui.QApplication.translate("wMainClass", "MainWindow", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox_2.setTitle(QtGui.QApplication.translate("wMainClass", "GaInOS Configure", None, QtGui.QApplication.UnicodeUTF8))
        self.trGaInOsCfgList.headerItem().setText(0, QtGui.QApplication.translate("wMainClass", "Object Configure", None, QtGui.QApplication.UnicodeUTF8))
        __sortingEnabled = self.trGaInOsCfgList.isSortingEnabled()
        self.trGaInOsCfgList.setSortingEnabled(False)
        self.trGaInOsCfgList.topLevelItem(0).setText(0, QtGui.QApplication.translate("wMainClass", "Task", None, QtGui.QApplication.UnicodeUTF8))
        self.trGaInOsCfgList.topLevelItem(1).setText(0, QtGui.QApplication.translate("wMainClass", "Resource", None, QtGui.QApplication.UnicodeUTF8))
        self.trGaInOsCfgList.topLevelItem(2).setText(0, QtGui.QApplication.translate("wMainClass", "Alarm", None, QtGui.QApplication.UnicodeUTF8))
        self.trGaInOsCfgList.setSortingEnabled(__sortingEnabled)
        self.tblGaInOsCfg.setWhatsThis(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p><br/></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_5.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Task Name:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.leTskName.setText(QtGui.QApplication.translate("wMainClass", "vTask", None, QtGui.QApplication.UnicodeUTF8))
        self.label_8.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Task Stack Size:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxTskStkSize.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOS ä»»åŠ¡å †æ ˆå¤§å°�</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_6.setText(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Task Type:</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTskType.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOSä»»åŠ¡ç±»åž‹</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTskType.setItemText(0, QtGui.QApplication.translate("wMainClass", "BASIC_TASK", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTskType.setItemText(1, QtGui.QApplication.translate("wMainClass", "EXTEND_TASK", None, QtGui.QApplication.UnicodeUTF8))
        self.label_7.setText(QtGui.QApplication.translate("wMainClass", "Task Priority:", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxTskPrio.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOS ä»»åŠ¡çš„ä¼˜å…ˆçº§</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_10.setText(QtGui.QApplication.translate("wMainClass", "Task Max Activate Count:", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxTskMaxActivateCount.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOSçš„æœ€å¤§æ¿€æ´»æ¬¡æ•°</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxTskAutoStart.setText(QtGui.QApplication.translate("wMainClass", "Task Auto-Start", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxTskPreemtable.setText(QtGui.QApplication.translate("wMainClass", "Task Preemtable", None, QtGui.QApplication.UnicodeUTF8))
        self.tblGaInOsCfg.setTabText(self.tblGaInOsCfg.indexOf(self.tabTask), QtGui.QApplication.translate("wMainClass", "Task", None, QtGui.QApplication.UnicodeUTF8))
        self.label_11.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Resource Name:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.leResName.setText(QtGui.QApplication.translate("wMainClass", "vRes1", None, QtGui.QApplication.UnicodeUTF8))
        self.label_12.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Resource Ceiling Priority:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxResCeilPrio.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOS æ™®é€šèµ„æº�å¤©èŠ±æ�¿ä¼˜å…ˆçº§</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.tblGaInOsCfg.setTabText(self.tblGaInOsCfg.indexOf(self.tabRes), QtGui.QApplication.translate("wMainClass", "Resource", None, QtGui.QApplication.UnicodeUTF8))
        self.label_15.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Counter Name:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.leCntName.setText(QtGui.QApplication.translate("wMainClass", "vCnt1", None, QtGui.QApplication.UnicodeUTF8))
        self.label_16.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Counter Max Allowed Value:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxCntMaxAllowedValue.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOSè®¡æ•°å™¨çš„è®¡æ•°ä¸Šé™�</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_17.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Counter Ticks Per Base:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxCntTickBase.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOSå®šæ—¶å™¨çš„è®¡æ•°åŸºæ•°</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_18.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Counter Minimum Cycle:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxCntMinCycle.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOSå®šæ—¶å™¨çš„æœ€å°�å…�è®¸å‘¨æœŸ</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.tblGaInOsCfg.setTabText(self.tblGaInOsCfg.indexOf(self.tabCnt), QtGui.QApplication.translate("wMainClass", "Counter", None, QtGui.QApplication.UnicodeUTF8))
        self.label_19.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Alarm Name:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.leAlarmName.setText(QtGui.QApplication.translate("wMainClass", "vAlarm1", None, QtGui.QApplication.UnicodeUTF8))
        self.label_24.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Alarm Owner:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmOwner.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmOwner.setItemText(0, QtGui.QApplication.translate("wMainClass", "tkernel system counter", None, QtGui.QApplication.UnicodeUTF8))
        self.label_20.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Alarm Type:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmType.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">é…�ç½®GaInOSæŠ¥è­¦å™¨çš„ç±»åž‹</p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmType.setItemText(0, QtGui.QApplication.translate("wMainClass", "callback", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmType.setItemText(1, QtGui.QApplication.translate("wMainClass", "task", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmType.setItemText(2, QtGui.QApplication.translate("wMainClass", "event", None, QtGui.QApplication.UnicodeUTF8))
        self.lblAlarmTask.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Alarm Event Task:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmTask.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_23.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Alarm Set Event:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxAlarmEvent.setToolTip(QtGui.QApplication.translate("wMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Monospace\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></td></tr></table></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.tblGaInOsCfg.setTabText(self.tblGaInOsCfg.indexOf(self.tabAlm), QtGui.QApplication.translate("wMainClass", "Alarm", None, QtGui.QApplication.UnicodeUTF8))
        self.label_25.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p><span style=\" font-size:12pt;\">Event Name:</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_26.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>Event Mask:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.tblGaInOsCfg.setTabText(self.tblGaInOsCfg.indexOf(self.tabEvent), QtGui.QApplication.translate("wMainClass", "Event", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("wMainClass", "Add", None, QtGui.QApplication.UnicodeUTF8))
        self.btnDel.setText(QtGui.QApplication.translate("wMainClass", "Delete", None, QtGui.QApplication.UnicodeUTF8))
        self.btnCheck.setText(QtGui.QApplication.translate("wMainClass", "Check", None, QtGui.QApplication.UnicodeUTF8))
        self.btnFileSave.setText(QtGui.QApplication.translate("wMainClass", "Save", None, QtGui.QApplication.UnicodeUTF8))
        self.btnGen.setText(QtGui.QApplication.translate("wMainClass", "^_^Gen^_^", None, QtGui.QApplication.UnicodeUTF8))
        self.label_22.setText(QtGui.QApplication.translate("wMainClass", "<html><head/><body><p>GaInOS Configure File:</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.leFileOpened.setText(QtGui.QApplication.translate("wMainClass", "None", None, QtGui.QApplication.UnicodeUTF8))
        self.btnFileOpen.setText(QtGui.QApplication.translate("wMainClass", "Open>>", None, QtGui.QApplication.UnicodeUTF8))
        self.menuGaInOS_Studio.setTitle(QtGui.QApplication.translate("wMainClass", "File", None, QtGui.QApplication.UnicodeUTF8))
        self.menuHelp.setTitle(QtGui.QApplication.translate("wMainClass", "Help", None, QtGui.QApplication.UnicodeUTF8))
        self.actionInfo.setText(QtGui.QApplication.translate("wMainClass", "Info", None, QtGui.QApplication.UnicodeUTF8))
        self.actionAbout.setText(QtGui.QApplication.translate("wMainClass", "About", None, QtGui.QApplication.UnicodeUTF8))
        self.actionNew.setText(QtGui.QApplication.translate("wMainClass", "New", None, QtGui.QApplication.UnicodeUTF8))
        self.actionOpen.setText(QtGui.QApplication.translate("wMainClass", "Open", None, QtGui.QApplication.UnicodeUTF8))
        self.actionOpen_Recent_Files.setText(QtGui.QApplication.translate("wMainClass", "Open Recent Files", None, QtGui.QApplication.UnicodeUTF8))
        self.actionClose.setText(QtGui.QApplication.translate("wMainClass", "Close", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave.setText(QtGui.QApplication.translate("wMainClass", "Save", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave_As.setText(QtGui.QApplication.translate("wMainClass", "Save As ...", None, QtGui.QApplication.UnicodeUTF8))
        self.actionQuit.setText(QtGui.QApplication.translate("wMainClass", "Quit", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    wMainClass = QtGui.QMainWindow()
    ui = Ui_wMainClass()
    ui.setupUi(wMainClass)
    wMainClass.show()
    sys.exit(app.exec_())

