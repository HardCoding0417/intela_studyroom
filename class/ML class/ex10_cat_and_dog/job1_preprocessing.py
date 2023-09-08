from PIL import Image
import glob
import numpy as np
from sklearn.model_selection import train_test_split

img_dir = '../datasets/cat_dog/train/'
categories = ['cat', 'dog']
img_width = 64
img_height = 64

img_val_cnt = img_width * img_height * 3
images = []
labels = []

for idx, category in enumerate(categories):
    files = glob.glob(img_dir + category + '*.jpg')
    for i, file in enumerate(files):
        try:
            img = Image.open(file)
            img = img.convert('RGB')  # JPG to RGB format
            img = img.resize((img_width, img_height))
            img = np.asarray(img)
            images.append(img)
            labels.append(idx)
            if i % 300 == 0:
                print(category + ':', file)
        except:
            print('error:', category, i)
images = np.array(images)
labels = np.array(labels)
images = images / 255.0
print(images[0])
print(labels[0])

training_images, test_images, training_labels, test_labels\
    = train_test_split(images, labels, test_size=0.1)
images_labels = (training_images, training_labels, test_images, test_labels)
np.save('../datasets/cat_dog/binary_image_data.npy', images_labels)
