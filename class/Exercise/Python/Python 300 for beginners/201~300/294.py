f = open('D:\\Users\\net02\\Desktop\\매수종목1.txt', 'r')


codes = []

while line := f.readline():
    codes.append(line.rstrip('\n'))

print(codes)


f.close()