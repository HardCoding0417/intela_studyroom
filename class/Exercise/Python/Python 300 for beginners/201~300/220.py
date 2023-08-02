def print_max(a: int, b: int, c: int):
    m = a
    if b > m:
        m = b
    if c > m:
        m = c
    print(m)

print_max(1, 2, 3)
print_max(1, 3, 2)
print_max(2, 1, 3)
print_max(2, 3, 1)
print_max(3, 1, 2)
print_max(3, 2, 1)