import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import *
from tensorflow.keras.callbacks import EarlyStopping
import matplotlib.pyplot as plt


# 7 continual failed epochs
early_stopping = EarlyStopping(monitor='val_binary_accuracy', patience=3)

training_images, training_labels, test_images, test_labels\
    = np.load('../datasets/cat_dog/binary_image_data.npy', allow_pickle=True)

model = Sequential([
    Conv2D(32, kernel_size=(3, 3), padding='same',
           input_shape=(64, 64, 3), activation='relu'),
    MaxPool2D(pool_size=(2, 2)),
    Conv2D(32, kernel_size=(3, 3), padding='same', activation='relu'),
    MaxPool2D(pool_size=(2, 2)),
    Conv2D(32, kernel_size=(3, 3), padding='same', activation='relu'),
    MaxPool2D(pool_size=(2, 2)),
    Flatten(),
    Dense(256, activation='relu'),
    Dense(1, activation='sigmoid')
])

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['binary_accuracy'])
fit_hist = model.fit(training_images, training_labels, batch_size=64,
                     epochs=100, validation_split=0.15, callbacks=early_stopping)
score = model.evaluate(test_images, test_labels)

print('eval loss:', score[0])
print('eval acc:', score[1])

model.save('./cat_and_dog_{}.h5'.format(str(np.around(score[1], 3))))

plt.plot(fit_hist.history['binary_accuracy'], label='binary_accuracy')
plt.plot(fit_hist.history['val_binary_accuracy'], label='val_binary_accuracy')
plt.legend()
plt.show()
plt.plot(fit_hist.history['loss'], label='loss')
plt.plot(fit_hist.history['val_loss'], label='val_loss')
plt.legend()
plt.show()
