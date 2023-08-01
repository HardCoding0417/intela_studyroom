rrn = input("주민등록번호: ").replace('-', '')

mult = 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5

sum = 0
for i in range(12):
    sum += int(rrn[i])*mult[i]
sum %= 11

if rrn[-1] == str(11 - sum)[-1]:
    print("유효한 주민등록번호입니다.")
else:
    print("유효하지 않은 주민등록번호입니다.")