a = [1, 5, 2, 6, 4, 3, 8, 7, 9]
length = len(a)

for i in range(length - 1):
    m = a[i]
    idx = i

    for j in range(i + 1, length):
        if a[j] > m:
            m = a[j]
            idx = j

    temp = a[i]
    a[i] = a[idx]
    a[idx] = temp

print(a)