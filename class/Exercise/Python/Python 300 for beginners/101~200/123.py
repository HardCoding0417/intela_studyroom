exchange = {'달러': 1167, '엔': 1.096, '유로': 1268, '위안': 171}

charge, curr = input("입력: ").split()
charge = float(charge)*exchange[curr]

print("%.15g 원" % charge)