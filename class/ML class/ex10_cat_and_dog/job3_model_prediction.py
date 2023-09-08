from PIL import Image
import numpy as np
from tensorflow.keras.models import load_model


path = './dataset/dog3.jpg'
model_path = './models/cat_and_dog_0.823.h5'

img = Image.open(path)
img = img.convert('RGB')
img = img.resize((64, 64))
img_data = np.asarray(img)
img_data = img_data.reshape(1, 64, 64, 3)
img_data = img_data / 255.0

model = load_model(model_path)
print(model.predict(img_data))
