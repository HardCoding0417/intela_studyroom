import sys
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *
import numpy as np
from PyQt5 import uic


form_window = uic.loadUiType('./calculator.ui')[0]  # 'Ui_Form' class


class Exam(QWidget, form_window):
    def __init__(self):
        super().__init__(None)
        self.setupUi(self)

        self.is_firstInput = True
        self.is_afterOperator = False

        self.left_operand = None
        self.operator = ''

        button_num = [self.button_0, self.button_1, self.button_2, self.button_3, self.button_4,
                      self.button_5, self.button_6, self.button_7, self.button_8, self.button_9]
        button_num_shortcut = [str(x) for x in range(10)]
        button_operator = [self.button_add, self.button_subtract,
                           self.button_multiply, self.button_divide]
        button_operator_shortcut = ['+', '-', '*', '/']
        for i in range(10):
            button_num[i].clicked.connect(self.button_num_clicked_slot)
            button_num[i].setShortcut(button_num_shortcut[i])
        for i in range(4):
            button_operator[i].clicked.connect(self.button_operator_clicked_slot)
            button_operator[i].setShortcut(button_operator_shortcut[i])
        self.button_equal.clicked.connect(self.button_equal_clicked_slot)
        self.button_equal.setShortcut('Return')
        self.button_clear.clicked.connect(self.button_clear_clicked_slot)
        self.button_clear.setShortcut('Escape')

    def calculate(self):
        right_operand = float(self.label_result.text())
        if self.operator == '+':
            self.left_operand += right_operand
        elif self.operator == '-':
            self.left_operand -= right_operand
        elif self.operator == '*':
            self.left_operand *= right_operand
        elif self.operator == '/':
            try:
                self.left_operand /= right_operand
            except ZeroDivisionError:
                self.label_result.setText('Cannot divide by 0')
                self.left_operand = None
                self.operator = ''
                return
        self.label_result.setText('%.15g' % self.left_operand)

    def button_num_clicked_slot(self):
        button_name = self.sender().objectName()

        if self.is_firstInput or self.label_result.text() == '0':
            self.label_result.setText('')
            self.is_firstInput = False
        self.label_result.setText(self.label_result.text() + button_name[-1])

        self.is_afterOperator = False

    def button_operator_clicked_slot(self):
        if not self.is_afterOperator:  # not after operator
            if self.operator != '':
                self.calculate()
            else:
                self.left_operand = float(self.label_result.text())
            self.is_firstInput = True

        operator_name = self.sender().objectName()[7:]
        if operator_name == 'add':
            self.operator = '+'
        elif operator_name == 'subtract':
            self.operator = '-'
        elif operator_name == 'multiply':
            self.operator = '*'
        elif operator_name == 'divide':
            self.operator = '/'

        self.is_afterOperator = True

    def button_equal_clicked_slot(self):
        if self.operator != '':
            self.calculate()
        self.operator = ''
        self.is_firstInput = True
        self.is_afterOperator = False

    def button_clear_clicked_slot(self):
        self.label_result.setText('0')
        self.left_operand = None
        self.operator = ''
        self.is_firstInput = True
        self.is_afterOperator = False


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = Exam()
    mainWindow.show()
    sys.exit(app.exec_())
