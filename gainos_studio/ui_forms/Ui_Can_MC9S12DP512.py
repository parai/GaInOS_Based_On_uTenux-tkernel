# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\github\GaInOS_Based_On_uTenux-tkernel\gainos_studio\ui_forms\Can_MC9S12DP512.ui'
#
# Created: Wed Mar 27 23:31:38 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_DlgCanMC9S12DP512(object):
    def setupUi(self, DlgCanMC9S12DP512):
        DlgCanMC9S12DP512.setObjectName(_fromUtf8("DlgCanMC9S12DP512"))
        DlgCanMC9S12DP512.resize(993, 568)
        DlgCanMC9S12DP512.setStyleSheet(_fromUtf8("font: 12pt \"Consolas\";"))
        self.groupBox = QtGui.QGroupBox(DlgCanMC9S12DP512)
        self.groupBox.setGeometry(QtCore.QRect(20, 10, 951, 131))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.checkBox = QtGui.QCheckBox(self.groupBox)
        self.checkBox.setGeometry(QtCore.QRect(300, 30, 171, 16))
        self.checkBox.setObjectName(_fromUtf8("checkBox"))
        self.widget = QtGui.QWidget(self.groupBox)
        self.widget.setGeometry(QtCore.QRect(20, 30, 259, 91))
        self.widget.setObjectName(_fromUtf8("widget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.widget)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.cbxDet = QtGui.QCheckBox(self.widget)
        self.cbxDet.setObjectName(_fromUtf8("cbxDet"))
        self.verticalLayout.addWidget(self.cbxDet)
        self.cbxDet_2 = QtGui.QCheckBox(self.widget)
        self.cbxDet_2.setObjectName(_fromUtf8("cbxDet_2"))
        self.verticalLayout.addWidget(self.cbxDet_2)
        self.cbxDet_3 = QtGui.QCheckBox(self.widget)
        self.cbxDet_3.setObjectName(_fromUtf8("cbxDet_3"))
        self.verticalLayout.addWidget(self.cbxDet_3)
        self.cbxDet_4 = QtGui.QCheckBox(self.widget)
        self.cbxDet_4.setObjectName(_fromUtf8("cbxDet_4"))
        self.verticalLayout.addWidget(self.cbxDet_4)
        self.widget1 = QtGui.QWidget(self.groupBox)
        self.widget1.setGeometry(QtCore.QRect(300, 50, 311, 27))
        self.widget1.setObjectName(_fromUtf8("widget1"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.widget1)
        self.horizontalLayout.setMargin(0)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.label = QtGui.QLabel(self.widget1)
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout.addWidget(self.label)
        self.spinBox = QtGui.QSpinBox(self.widget1)
        self.spinBox.setMinimumSize(QtCore.QSize(101, 0))
        self.spinBox.setMinimum(1)
        self.spinBox.setMaximum(65535)
        self.spinBox.setProperty(_fromUtf8("value"), 10)
        self.spinBox.setObjectName(_fromUtf8("spinBox"))
        self.horizontalLayout.addWidget(self.spinBox)
        self.label_2 = QtGui.QLabel(self.widget1)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.horizontalLayout.addWidget(self.label_2)
        self.groupBox_2 = QtGui.QGroupBox(DlgCanMC9S12DP512)
        self.groupBox_2.setGeometry(QtCore.QRect(20, 150, 951, 401))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.treeWidget = QtGui.QTreeWidget(self.groupBox_2)
        self.treeWidget.setGeometry(QtCore.QRect(20, 30, 256, 361))
        self.treeWidget.setObjectName(_fromUtf8("treeWidget"))
        item_0 = QtGui.QTreeWidgetItem(self.treeWidget)
        item_0 = QtGui.QTreeWidgetItem(self.treeWidget)
        self.tabWidget = QtGui.QTabWidget(self.groupBox_2)
        self.tabWidget.setGeometry(QtCore.QRect(480, 30, 461, 361))
        self.tabWidget.setObjectName(_fromUtf8("tabWidget"))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.tabWidget.addTab(self.tab, _fromUtf8(""))
        self.tab_2 = QtGui.QWidget()
        self.tab_2.setObjectName(_fromUtf8("tab_2"))
        self.tabWidget.addTab(self.tab_2, _fromUtf8(""))
        self.tab_3 = QtGui.QWidget()
        self.tab_3.setObjectName(_fromUtf8("tab_3"))
        self.tabWidget.addTab(self.tab_3, _fromUtf8(""))
        self.widget2 = QtGui.QWidget(self.groupBox_2)
        self.widget2.setGeometry(QtCore.QRect(290, 50, 181, 62))
        self.widget2.setObjectName(_fromUtf8("widget2"))
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.widget2)
        self.verticalLayout_2.setMargin(0)
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.pushButton = QtGui.QPushButton(self.widget2)
        self.pushButton.setObjectName(_fromUtf8("pushButton"))
        self.verticalLayout_2.addWidget(self.pushButton)
        self.pushButton_2 = QtGui.QPushButton(self.widget2)
        self.pushButton_2.setObjectName(_fromUtf8("pushButton_2"))
        self.verticalLayout_2.addWidget(self.pushButton_2)

        self.retranslateUi(DlgCanMC9S12DP512)
        self.tabWidget.setCurrentIndex(2)
        QtCore.QMetaObject.connectSlotsByName(DlgCanMC9S12DP512)

    def retranslateUi(self, DlgCanMC9S12DP512):
        DlgCanMC9S12DP512.setWindowTitle(QtGui.QApplication.translate("DlgCanMC9S12DP512", "MSCAN(MC9S12DP512)  Autosar", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("DlgCanMC9S12DP512", "Can General", None, QtGui.QApplication.UnicodeUTF8))
        self.checkBox.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanVersionInfoApi", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDet.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanDevErrorDetection", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDet_2.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanHardwareCancellation", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDet_3.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanIdenticalIdCancellation", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDet_4.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanMultiplexedTransmission", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanTimeoutDuration:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox_2.setTitle(QtGui.QApplication.translate("DlgCanMC9S12DP512", "Can Controller", None, QtGui.QApplication.UnicodeUTF8))
        self.treeWidget.headerItem().setText(0, QtGui.QApplication.translate("DlgCanMC9S12DP512", "Can", None, QtGui.QApplication.UnicodeUTF8))
        __sortingEnabled = self.treeWidget.isSortingEnabled()
        self.treeWidget.setSortingEnabled(False)
        self.treeWidget.topLevelItem(0).setText(0, QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanController ", None, QtGui.QApplication.UnicodeUTF8))
        self.treeWidget.topLevelItem(1).setText(0, QtGui.QApplication.translate("DlgCanMC9S12DP512", "CanHardwareObject ", None, QtGui.QApplication.UnicodeUTF8))
        self.treeWidget.setSortingEnabled(__sortingEnabled)
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), QtGui.QApplication.translate("DlgCanMC9S12DP512", "Controller", None, QtGui.QApplication.UnicodeUTF8))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), QtGui.QApplication.translate("DlgCanMC9S12DP512", "Hardware Object", None, QtGui.QApplication.UnicodeUTF8))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), QtGui.QApplication.translate("DlgCanMC9S12DP512", "Filter Mask", None, QtGui.QApplication.UnicodeUTF8))
        self.pushButton.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "Add Hardware Object", None, QtGui.QApplication.UnicodeUTF8))
        self.pushButton_2.setText(QtGui.QApplication.translate("DlgCanMC9S12DP512", "Del", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    DlgCanMC9S12DP512 = QtGui.QDialog()
    ui = Ui_DlgCanMC9S12DP512()
    ui.setupUi(DlgCanMC9S12DP512)
    DlgCanMC9S12DP512.show()
    sys.exit(app.exec_())

