# -*- coding: utf-8 -*-
"""ex1_introduction_to_machine_learning.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1QMxFMGm3cEmFqcxyGIiV3-yCn9Cjh_KL

#머신러닝 기초

##기존 프로그래밍 방식
"""

def celsius_to_fahrenheit(x):
  return x * 1.8 + 32

celsius_val = int(input("Enter temperature in Celsius: "))
print(celsius_to_fahrenheit(celsius_val), "in Fahrenheit")

"""##머신러닝 방식"""

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, InputLayer
import numpy as np
import matplotlib.pyplot as plt

data_C = np.array(range(100))
data_F = celsius_to_fahrenheit(data_C)
print(data_C)
print(data_F)

model = Sequential()
model.add(InputLayer(input_shape=(1,)))
model.add(Dense(1))
model.compile(loss='mse', optimizer='rmsprop')
model.summary()

scaled_data_C = data_C / 100
scaled_data_F = data_F / 100
print(scaled_data_C)
print(scaled_data_F)

print(model.predict([0.01]))

model.save('before_learning.h5') # .h5

fit_hist = model.fit(scaled_data_C, scaled_data_F, epochs=1000)

print(model.predict([25]))

model.save('after_learning.h5')

plt.plot(fit_hist.history['loss'])
plt.show()

noise = np.array(np.random.normal(0, 0.05, 100))
print(noise)

noised_scaled_data_F = np.array([])
for data in scaled_data_F:
  noised_scaled_data_F = np.append(
      noised_scaled_data_F,
      np.random.normal(0, 0.05, 100) + data
  )

print(noised_scaled_data_F)
print(len(noised_scaled_data_F))

noised_scaled_data_C = []
for data in range(100):
  for i in range(100):
    noised_scaled_data_C.append(data)
noised_scaled_data_C = np.array(noised_scaled_data_C)
noised_scaled_data_C = noised_scaled_data_C / 100

print(noised_scaled_data_C)
print(len(noised_scaled_data_C))

plt.scatter(x=noised_scaled_data_C, y=noised_scaled_data_F)
plt.show()

fig = plt.figure(figsize=(50, 50))
ax = fig.add_subplot(111)
ax.scatter(x=noised_scaled_data_C,
           y=noised_scaled_data_F,
           alpha=0.2, s=200, marker='+')
plt.show()

model2 = Sequential()
model2.add(InputLayer(input_shape=(1,)))
model2.add(Dense(1))
model2.compile(loss='mse', optimizer='rmsprop')
model2.summary()

print(model2.predict([0.01]))

fit_hist2 = model2.fit(noised_scaled_data_C,
                      noised_scaled_data_F,
                      epochs=20)

model2.save('noised_after_learning.h5')

print(model2.predict([0.01]))

plt.plot(fit_hist2.history['loss'])
plt.show()

celsius_val = float(input('Enter a temperature in Celsius: '))
print('Temperature in Fahrenheit:',
      np.around(model2.predict([celsius_val / 100])[0][0] * 100))