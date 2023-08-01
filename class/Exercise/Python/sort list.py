a = [4, 6, 2, 1, 8, 5, 3, 2, 8, 9, 6]

a.sort()
print(a)
a.reverse()
print(a)
a = list(set(a))
a.sort(reverse = True)
print(a)