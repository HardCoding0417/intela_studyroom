wire_service = {'011': 'SKT', '016': 'KT', '019': 'LGU'}

first_digits = input("휴대전화 번호 입력: ")[:3]

if first_digits in wire_service:
    print(f"당신은 {wire_service[first_digits]} 사용자입니다.")
else:
    print("알 수 없는 통신사")