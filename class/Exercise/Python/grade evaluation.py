kor = int(input("국어: "))
eng = int(input("영어: "))
math = int(input("수학: "))
att = int(input("출석: "))

avg = (kor + eng + math)/3


if avg >= 90:
    grade = 'A'
elif avg >= 80:
    grade = 'B'
elif avg >= 70:
    grade = 'C'
elif avg >= 60:
    grade = 'D'
else:
    grade = 'F'

print(grade, end = '')

if att >= 80:
    print('+', end = '')
