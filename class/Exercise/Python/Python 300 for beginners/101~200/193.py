data = [
    [2000, 3050, 2050, 1980],
    [7500, 2050, 2050, 1980],
    [15450, 15050, 15550, 14900]
]

commision_mult = 1.00014

result = []
for stock in data:
    for price in stock:
        result.append(float("%.15g" % (price*commision_mult)))

print(result)