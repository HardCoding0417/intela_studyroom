import sys
import numpy as np
from PIL import Image
from tensorflow.keras.models import load_model
from PyQt5 import uic
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *

form_window = uic.loadUiType('./cat_and_dog.ui')[0]  # 'Ui_Form' class


class Exam(QWidget, form_window):
    def __init__(self):
        super().__init__(None)
        self.setupUi(self)
        self.setFixedWidth(600)
        self.setFixedHeight(600)
        self.button_open.clicked.connect(self.button_open_clicked_slot)

        self.path = ('./dataset/cat1.jpg', '')
        pixmap = QPixmap(self.path[0])
        self.label_image.setPixmap(pixmap)

        model_path = './models/cat_and_dog_0.823.h5'
        self.model = load_model(model_path)

    def button_open_clicked_slot(self):
        old_path = self.path
        self.path = QFileDialog.getOpenFileName(self, 'Open file',
                                           './dataset/',
                                           'Image Files(*.jpg;*.png);;All Files(*.*)')
        if self.path[0] == '':
            self.path = old_path
            return
        try:
            pixmap = QPixmap(self.path[0])
            self.label_image.setPixmap(pixmap)

            img = Image.open(self.path[0])
            img = img.convert('RGB')
            img = img.resize((64, 64))
            img_data = np.asarray(img)
            img_data = img_data.reshape(1, 64, 64, 3)
            img_data = img_data / 255.0

            categories = ['cat', 'dog']
            prediction = self.model.predict(img_data)[0][0]
            print(prediction)
            self.label_description_and_result.setText(categories[round(prediction)])
        except FileNotFoundError:
            print('error: {}'.format(self.path[0]))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = Exam()
    mainWindow.show()
    sys.exit(app.exec_())
