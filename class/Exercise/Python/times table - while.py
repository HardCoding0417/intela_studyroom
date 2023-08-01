n = 2
while n < 10:
    i = 1 
    while i < 10:
        print(f"{n} * {i} = {n*i}")
        i += 1
    print()
    n += 1


exc_n = int(input("출력하고 싶지 않은 단 수: "))

n = 1
while n < 9:
    n += 1
    if n == exc_n:
        continue

    i = 1 
    while i < 10:
        print(f"{n} * {i} = {n*i}")
        i += 1
    print()


n = 3
while n < 10:
    i = 1
    while i < 10:
        print(f"{n} * {i} = {n*i}")
        i += 1
    print()
    n += 2