zip_code = input("우편번호: ")

if zip_code.startswith('01'):
    mid = zip_code[2]
    if mid <= '2':
        print("강북구")
    elif mid <= '5':
        print("도봉구")
    else:
        print("노원구")
else:
    print("?")