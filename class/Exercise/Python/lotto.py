import random

num_list = []

cnt = 0
while(cnt != 6):
    num = random.randint(1, 45)
    if num in num_list:
        continue
    else:
        num_list.append(num)
        cnt += 1

num_list.sort()
for num in num_list:
    print(num, end = ' ')