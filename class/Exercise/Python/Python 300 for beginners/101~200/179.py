my_list = [100, 200, 400, 800, 1000, 1300]

for i in range(len(my_list) - 2):
    print("%.2f" % (sum(my_list[i:i + 3])/3))