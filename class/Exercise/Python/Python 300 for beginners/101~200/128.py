rrn = input("주민등록번호: ")

if rrn[8] == '0' and rrn[9] <= '8':
    print("서울 입니다.")
else:
    print("서울이 아닙니다.")