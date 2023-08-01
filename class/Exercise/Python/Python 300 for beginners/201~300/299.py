data = [1, 2, 3]

try:
    for i in range(5):
        print(data[i])
except IndexError as err:
    print(err)