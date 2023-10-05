import sys
from PIL import Image
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import *
from PyQt5 import uic
import numpy as np
from tensorflow.keras.models import load_model
import cv2
import time


form_window = uic.loadUiType('./cat_and_dog.ui')[0]  # 'Ui_Form' class


class Exam(QWidget, form_window):
    def __init__(self):
        super().__init__(None)
        self.setupUi(self)

        self.img_path = './dataset/capture.png'
        self.model = load_model('./models/cat_and_dog_0.823.h5')

        self.capture = cv2.VideoCapture(0)
        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

        self.button_open.clicked.connect(self.button_open_clicked_slot)

    def button_open_clicked_slot(self):
        while True:
            is_captured, frame = self.capture.read()
            if is_captured:
                cv2.imshow('VideoFrame', frame)
                cv2.imwrite(self.img_path, frame)
            # time.sleep(0.01)

            key = cv2.waitKey(1)
            if key == 27:
                break

            pixmap = QPixmap(self.img_path)
            self.label_image.setPixmap(pixmap)

            try:
                img = Image.open(self.img_path)
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
                print('error: {}'.format(self.img_path))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = Exam()
    mainWindow.show()
    sys.exit(app.exec_())
