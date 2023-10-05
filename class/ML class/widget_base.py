import sys
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *
import numpy as np
from PyQt5 import uic


form_window = uic.loadUiType('./ex10_cat_and_dog/cat_and_dog.ui')[0]  # 'Ui_Form' class


class Exam(QWidget, form_window):
    def __init__(self):
        super().__init__(None)
        self.setupUi(self)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = Exam()
    mainWindow.show()
    sys.exit(app.exec_())
