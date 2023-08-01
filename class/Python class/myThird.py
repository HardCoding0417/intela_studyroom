# a = 1 + 2j
# print(type(a)) # <class 'complex'>

# a = 1
# print(type(a)) # <class 'int'>

# a = 1.1
# print(type(a)) # <class 'float'>

# a = '파이썬 이미,\n 시작'
# print(type(a)) # <class 'str'>
# print(a) # 파이썬 이미,
# #           시작

# a = '''와
#   정
#     말
#       요'''
# print(a) # 와
# #            정
# #              말
# #                요

# b = "큰따옴표도 문자열"
# print(len(b)) # 9

# x = 3
# print(id(x)) # (address of x)

# a = '안녕하세요'

# print(a[0]) # 안
# print(a[-1]) # 요
# try:
#     print(a[5])
# except:
#     print("IndexError")
# try:
#     print(a[-6])
# except:
#     print("IndexError")
# print(a[:3]) # 안녕하
# print(a[::]) # 안녕하세요
# print(a[:]) # 안녕하세요
# print(a[::2]) # 안하요

# a = '1,2,3,4,5,6,7,8,9'
# print(len(a)) # 17
# print(a[::2]) # 123456789

# b = '987654321'
# print(b[::-1]) # 123456789

# a = 'abcdabcd'
# print(a.find('b')) # 1
# print(a.find('e')) # -1
# print(a.replace('b', '!!')) # a!!cda!!cd
# print(a.split('b')) # ['a', 'cda', 'cd']
# print(a.split('a')) # ['', 'bcd', 'bcd']

# c = 12345
# print(str(c)) # 12345

# print(type(9 / 3)) # <class 'float'>
# print(int(5 / 3)) # 1
# print(5 // 3) # 1
# print(5 % 3) # 2
# print(5 ** 3) # 125

# b = 5
# b **= 3
# print(b) # 125

# print(pow(5, 3)) # 125
# print(divmod(5, 3)) # (1, 2)

# import math
# print(math.sqrt(4)) # 2.0

# a = [1, 2, 3, 4]
# print(type(a)) # <class 'list'>
# print(a) # [1, 2, 3, 4]

# a = [1, 2, [1.1, 2], 'a']
# print(a[2]) # [1.1, 2]
# print(a[:2]) # [1, 2]

# a = [4, 1, 3, 2]
# a.append(5)
# print(a) # [4, 1, 3, 2, 5]
# a.remove(2)
# print(a) # [4, 1, 3, 5]
# a.sort()
# print(a) # [1, 3, 4, 5]

# a = a.append(2)
# print(type(a)) # <class 'NoneType'>

# a = [1, 2, [1.1, 2], 'a']

# a[2].remove(2)
# print(a) # [1, 2, [1.1], 'a']

# a = [4, 1, 3, 2]
# print(a[::-1]) # [2, 3, 1, 4]
# print(a) # [4, 1, 3, 2]

# a.reverse()
# print(a) # [2, 3, 1, 4]

# b = 0b11
# print(b) # 3
# c = 0o12
# print(c) # 10
# d = 0x23
# print(d) # 35

# b = 2e-4
# print(type(b)) # <class 'float'>
# print(b) # 0.0002
# c = 3e3
# print(c) # 3000.0

# print('Hello, ' + 'World!') # Hello, World!
# print('죄송합니다' * 3) # 죄송합니다죄송합니다죄송합니다

# a = '12345'
# b = '34567'
# print(a[:2] + b[:]) # 1234567

# a = 'abcDEfGhi abc'
# print(a.upper()) # ABCDEFGHI ABC
# print(a.lower()) # abcdefghi abc
# print(a.swapcase()) # ABCdeFgHI ABC
# print(a.replace('bc', '1')) # a1DEfGhi a1
# print(a.capitalize()) # AbcDEfGhi abc
# print(a.title()) # AbcDEfGhi Abc

# a = ['a', 'b', 'c']
# print('#'.join(a)) # a#b#c

# a = '  abcd efg   '
# print(a) # *  abcd efg   *
# print(a.strip() + '*') # abcd efg*
# print(a.lstrip() + '*') # abcd efg   *
# print(a.rstrip() + '*') # -  abcd efg*-
# print(a.index('b')) # 3

# li = list()
# print(li, type(li)) # [] <class 'list'>

# li = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# print(li[len(li) - 1]) # 9
# li[0] = [1, 2]
# li[1] = type(li[1])
# print(li) # [[1, 2], <class 'int'>, 3, 4, 5, 6, 7, 8, 9]

# tu = tuple()
# print(tu, type(tu)) # () <class 'tuple'>

# tu = (1, 2, 3)
# print(tu[1], tu[:1]) # 2 (1,)

# li = [1, 2, 3]
# tu = 1, 2, (1, 2)
# print(li + li) # [1, 2, 3, 1, 2, 3]
# print(tu + tu) # (1, 2, (1, 2), 1, 2, (1, 2))

# a = {'key': 'value',
#      1: [1, 2, 3],
#      (1, 2): 'a'}
# print(type(a)) # <class 'dict'>
# print(a) # {'key': 'value', 1: [1, 2, 3], (1, 2): 'a'}
# print(a[1]) # [1, 2, 3]
# print(a[(1, 2)]) # a

# d = {'이름': '최명수', '주소': '서울시', '전화': '010-4243-9882'}
# print(d.keys()) # dict_keys(['이름', '주소', '전화'])
# print(d.values()) # dict_values(['최명수', '서울시', '010-4243-9882'])
# print(d.items()) # dict_items([('이름', '최명수'), ('주소', '서울시'), ('전화', '010-4243-9882')])

# a = {1, 2, 3, 4, 5}
# print(type(a)) # <class 'set'>
# print(a) # {1, 2, 3, 4, 5}

# a = [1, 2, 1, 1, 1, 2, 3, 4, 2, 2, 3, 4, 5, 6, 7, 8, 0, 0, 2]
# a = list(set(a))
# print(a) # [0, 1, 2, 3, 4, 5, 6, 7, 8]

# s = 'hello'
# s = set(s)
# print(s) # {'e', 'o', 'l', 'h'}

# s1 = {1, 2, 3, 4, 5, 6}
# s2 = {4, 5, 6, 7, 8, 9}
# print(s1 & s2) # {4, 5, 6}
# print(s1 | s2) # {1, 2, 3, 4, 5, 6, 7, 8, 9}
# print(s1 - s2) # {1, 2, 3}
# print(s1.intersection(s2)) # {4, 5, 6}
# print(s1.union(s2)) # {1, 2, 3, 4, 5, 6, 7, 8, 9}
# print(s1.difference(s2)) # {1, 2, 3}

# s = {1, 2, 3}
# s.add(4)
# print(s) # {1, 2, 3, 4}
# s.remove(2)
# print(s) # {1, 3, 4}
# s.update((6, 7))
# print(s) # {1, 3, 4, 6, 7}

# T = (1, 2, 3, 4, 5, 6, 7, 8)
# T = list(T)
# T[0] = 0
# print(tuple(T)) # (0, 2, 3, 4, 5, 6, 7, 8)
# T.append(9)
# print(tuple(T)) # (0, 2, 3, 4, 5, 6, 7, 8, 9)
# T.remove(8)
# T = tuple(T)
# print(T) # (0, 2, 3, 4, 5, 6, 7, 9)

# a = True
# print(type(a)) # <class 'bool'>

# print(bool(0)) # False
# print(bool(2)) # True
# print(bool(0.)) # False
# print(bool(3.14)) # True
# print(bool('')) # False
# print(bool('False')) # True
# print(bool([])) # False
# print(bool(['False'])) # True
# print(bool(tuple())) # False
# print(bool((0,))) # True
# print(bool({})) # False
# print(bool({'False': '거짓'})) # True
# print(bool(set())) # False
# print(bool({0})) # True

# print(0 == 0) # True
# print(1 != 1) # False
# print(0 > -1) # True
# print(1 <= 0) # False

# a = True
# b = False
# print(a and b) # False
# print(a and not b) # True
# print(b or a) # True

# a, b = 1, 2
# print(a > 0 and b <= 2) # True
# print(a == 0 or b != 2) # False

# print('a' and 'b') # True
# print('a' and '') # False
# print('' or '') # False
# print('' or 'b') # True

# a = 2
# msg = 'a is 1' if a == 1 else 'a is not 1'
# print(msg) # a is not 1

# for i in '1234':
#     print(i, end = ' ')
# print()
# # 1 2 3 4

# for i in range(1, 101, 2):
#     print(i, end = ' ')
# print()
# # 1, 3, 5, ..., 99

# for i in {3, 2, 1}:
#     print(i, end = ' ')
# print()
# # 3 2 1

# import collections.abc
# print(isinstance(1234, collections.abc.Iterable))
# print(isinstance([], collections.abc.Iterable))

# num = 5
# while num > 0:
#     print(num)
#     num -= 1
# # 5\n4\n3\n2\n1\n

# f = open('D:\\a.txt', 'w')
# f.write('Hello')
# f.close()
# f = open('D:\\a.txt', 'a')
# f.write('\nWorld')
# f.close()
# f = open('D:\\a.txt', 'r')
# print(f.read())
# f.close()

# def gugu(x = 9):
#     for i in range(1, 10):
#         print(f"{x} * {i} = {x * i}")
# gugu()

# def func(x, y, z, a, b = 0, c = 1):
#     print(x, y, z, a, b, c)
# func(1, 2, 3, 4, 5, 6) # 1, 2, 3, 4, 5, 6
# func(1, 2, 3, 4, 5) # 1, 2, 3, 4, 5, 1
# func(1, 2, 3, 4, c = 5) # 0, 5
# func(1, 2, 3, 4) # 0, 1

# def func():
#     a = 2
#     print(a)
# a = 1
# func() # 2
# print(a) # 1

# print("%") # %
# print("%d / %d = %5.1f" % (1, 2, .5)) # 1 / 2 =   0.5
# print("%5d" % 123) # *  123
# print("%05d" % 123) # 00123
# print("%f" % 123.45) # 123.450000
# print("{0} {1} {2}".format(123, 456, 789))
# print(r"\n \t \" \\ %d")

# def func(a, *args):
#     print(a)
#     print(args)
# print(func(1, 2, 3)) # 1\n(2, 3)\nNone

# import os
# print(os.getcwd())

