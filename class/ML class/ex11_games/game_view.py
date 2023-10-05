import sys
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *
import numpy as np
from PyQt5 import uic


form_window = uic.loadUiType('./games.ui')[0]  # 'Ui_Form' class


class Exam(QWidget, form_window):
    def __init__(self):
        super().__init__(None)
        self.setupUi(self)

        self.button_minecraft.clicked.connect(self.button_clicked_slot)
        self.button_touhou7.clicked.connect(self.button_clicked_slot)
        self.button_touhou6.clicked.connect(self.button_clicked_slot)
        self.button_mahjong_soul.clicked.connect(self.button_clicked_slot)

    def button_clicked_slot(self):
        self.label_minecraft.hide()
        self.label_touhou7.hide()
        self.label_touhou6.hide()
        self.label_mahjong_soul.hide()

        button_name = self.sender().objectName()
        if button_name == 'button_minecraft':
            self.label_minecraft.show()
        elif button_name == 'button_touhou7':
            self.label_touhou7.show()
        elif button_name == 'button_touhou6':
            self.label_touhou6.show()
        elif button_name == 'button_mahjong_soul':
            self.label_mahjong_soul.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = Exam()
    mainWindow.show()
    sys.exit(app.exec_())
