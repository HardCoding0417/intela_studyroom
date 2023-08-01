f = open('D:\\Users\\net02\\Desktop\\매수종목2.txt', 'r')


stock_dict = {}

while line := f.readline():
    key, value = line.split()
    stock_dict[key] = value

print(stock_dict)


f.close()