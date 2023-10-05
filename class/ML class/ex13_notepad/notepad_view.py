import sys
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *
import numpy as np
from PyQt5 import uic


form_window = uic.loadUiType('./notepad.ui')[0]  # 'Ui_Form' class


class Exam(QMainWindow, form_window):
    def __init__(self):
        super().__init__(None)
        self.setupUi(self)

        self.is_textChanged = False

        self.file_path = ''
        self.file_name = 'new'
        self.title_endString = ' - Qt Notepad'

        self.setWindowTitle(self.file_name + self.title_endString)

        self.action_new.triggered.connect(self.action_new_slot)
        self.action_open.triggered.connect(self.action_open_slot)
        self.action_save.triggered.connect(self.action_save_slot)
        self.action_saveAs.triggered.connect(self.action_save_as_slot)
        self.action_exit.triggered.connect(self.action_exit_slot)
        self.action_undo.triggered.connect(self.plainTextEdit.undo)
        self.action_redo.triggered.connect(self.plainTextEdit.redo)
        self.action_cut.triggered.connect(self.plainTextEdit.cut)
        self.action_copy.triggered.connect(self.plainTextEdit.copy)
        self.action_paste.triggered.connect(self.plainTextEdit.paste)
        self.action_preferences.triggered.connect(self.action_font_slot)
        self.action_about_notepad.triggered.connect(self.action_about_notepad_slot)

        self.plainTextEdit.textChanged.connect(self.text_changed_slot)

    def action_new_slot(self):
        if self.is_textChanged:
            selection = QMessageBox.question(
                self, 'Save', 'Save file "%s" ?' % self.file_name,
                QMessageBox.Yes | QMessageBox.No | QMessageBox.Cancel, QMessageBox.Yes)
            if selection == QMessageBox.Yes:
                if self.action_save_slot() == -1:  # if canceled
                    return
            elif selection == QMessageBox.No:
                pass
            elif selection == QMessageBox.Cancel:
                return
        self.plainTextEdit.setPlainText('')
        self.file_name = 'new'
        self.setWindowTitle(self.file_name + self.title_endString)
        self.is_textChanged = False

    def action_open_slot(self):
        open_path = QFileDialog.getOpenFileName(
            self, 'Open file', '', 'Text Files(*.txt);;All Files(*.*)')[0]
        if open_path != '':
            if self.is_textChanged:
                selection = QMessageBox.question(
                    self, 'Save', 'Save file "%s" ?' % self.file_name,
                                  QMessageBox.Yes | QMessageBox.No | QMessageBox.Cancel, QMessageBox.Yes)
                if selection == QMessageBox.Yes:
                    if self.action_save_slot() == -1:  # if canceled
                        return
                elif selection == QMessageBox.No:
                    pass
                elif selection == QMessageBox.Cancel:
                    return
            with open(open_path, 'r') as f:
                text_read = f.read()
            self.plainTextEdit.setPlainText(text_read)
            self.file_path = open_path
            self.file_name = open_path.split('/')[-1].split('.')[0]
            self.setWindowTitle(self.file_name + self.title_endString)
            self.is_textChanged = False

    def action_save_slot(self):
        if self.file_path != '':
            with open(self.file_path, 'w') as f:
                f.write(self.plainTextEdit.toPlainText())
            self.setWindowTitle(self.file_name + self.title_endString)
            self.is_textChanged = False
            return 0  # saved
        else:
            return self.action_save_as_slot()

    def action_save_as_slot(self):
        save_path = QFileDialog.getSaveFileName(
            self, 'Save file', '', 'Text Files(*.txt);;All Files(*.*)')[0]

        if save_path != '':
            with open(save_path, 'w') as f:
                f.write(self.plainTextEdit.toPlainText())
            self.file_path = save_path
            self.file_name = save_path.split('/')[-1].split('.')[0]
            self.setWindowTitle(self.file_name + self.title_endString)
            self.is_textChanged = False
            return 0  # saved
        else:
            return -1  # canceled

    def action_exit_slot(self):
        if self.is_textChanged:
            selection = QMessageBox.question(
                self, 'Save', 'Save file "%s" ?' % self.file_name,
                              QMessageBox.Yes | QMessageBox.No | QMessageBox.Cancel, QMessageBox.Yes)
            if selection == QMessageBox.Yes:
                if self.action_save_slot() == -1:  # if canceled
                    return
            elif selection == QMessageBox.No:
                pass
            elif selection == QMessageBox.Cancel:
                return
        self.close()

    def action_font_slot(self):
        font, be_applied = QFontDialog.getFont()
        if be_applied:
            self.plainTextEdit.setFont(font)

    def action_about_notepad_slot(self):
        QMessageBox.about(
            self, 'Qt Notepad',
            '''Programmed by isocy''')

    def text_changed_slot(self):
        self.setWindowTitle('*' + self.file_name + self.title_endString)
        self.is_textChanged = True


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = Exam()
    mainWindow.show()
    sys.exit(app.exec_())
