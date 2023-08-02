for n in range(2, 10):
    for i in range(1, 10):
        print(f"{n} * {i} = {n*i}")
    print()


exc_n = int(input("출력하고 싶지 않은 단 수: "))

for n in range(2, 10):
    if n == exc_n:
        continue
    for i in range(1, 10):
        print(f"{n} * {i} = {n*i}")
    print()


for n in range(3, 10, 2):
    for i in range(1, 10):
        print(f"{n} * {i} = {n*i}")
    print()