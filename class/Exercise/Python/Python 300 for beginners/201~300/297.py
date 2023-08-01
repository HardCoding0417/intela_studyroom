per = ["10.31", "", "8.00"]

new_list = []
for i in per:
    try:
        new_list.append(float(i))
    except:
        new_list.append(0)

print(new_list)