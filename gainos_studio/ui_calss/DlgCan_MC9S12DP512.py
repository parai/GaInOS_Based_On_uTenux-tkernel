# -*- coding: utf-8 -*-

"""
Module implementing DlgCanMC9S12DP512.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature

from Ui_Can_MC9S12DP512 import Ui_DlgCanMC9S12DP512

class DlgCanMC9S12DP512(QDialog, Ui_DlgCanMC9S12DP512):
    """
    Class documentation goes here.
    """
    def __init__(self, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
