##### <data type - number> #####

# 1) int
# 2) float
# 3) complex




# a = 1 + 2j
# print(type(a)) # <class 'complex'>

# a = 1
# print(type(a)) # <class 'int'>

# a = 1.1
# print(type(a)) # <class 'float'>

# a = '파이썬 이미,\n 시작' # newline character(escape sequence)
# print(type(a)) # <class 'str'>
# print(a)

# a = '''와
#   정
#     말
#       요'''
# print(a)


# b = "큰따옴표도 문자열"
# print(len(b)) # 9



# x = 3
# print(id(x)) # 객체의 주소값 반환
# # 변수에 저장되는 것은 실제값이 아닌 객체의 주소


# a = '안녕하세요'

# print(a[0])
# print(a[-1])
# # a[5], a[-6]: string index out of range
# print(a[0:3]) # '안녕하세'가 아닌 '안녕하'
# print(a[::])
# print(a[::2])


# a = '1,2,3,4,5,6,7,8,9'
# print(len(a))

# print(a[::2]) # 1~9 숫자만 출력하고 싶다면?


# b = '987654321'

# print(b[::-1]) # 1~9




##### <function of 'str'> #####




# a = 'abcdabcd'

# print(a.find('b'))
# print(a.replace('b', '!!'))
# # replace() replaces all the strings found
# # return value of a.replace(): [r]value of a (new object)
# print(a.split('b'))

# # Ctrl-LeftClick the command to check the syntax
# help(a.find)



# c = 12345
# c = str(c) # 'int' -> 'str'




##### <operator: +, -, *, **, /, //, %> #####
#                +=,-=,*=,**=,/=,//=,%=




# print(5 + 3)

# a = 3 - 2
# print(a)

# print(type(9/3)) # thus 3.0 // result of division is always float
# print(int(5/3)) # 1
# print(5//3) # 1 // '/' in C
# print(5%3)
# print(5**3) # '^'


# a = 5
# a += 3
# print(a) # 8
# a -= 2
# print(a) # 6

# b = 5
# b **= 3
# print(b)


# print(pow(5, 3))
# print(divmod(5, 3)) # 'tuple'
# # 그 외의 수학에 쓰이는 함수들은 math 모듈에서 사용

# import math # import math.py

# print(math.sqrt(8)) # 2*root(2)




##### <list: '[]' & ','> #####
# stroes arbitrary objects sequentially
# can change elements directly contrast to 'str'




# a = [1, 2, 3, 4]
# print(type(a)) # <class 'list'>
# print(a)


# a = [1, 2, [1.1, 2], 'a']

# print(a[2])
# print(a[:2])




##### <function of 'list'> #####
# append(), remove(), sort(), reverse()




# a = [4, 1, 3, 2]

# a.append(5) # no return value
# print(a)
# a.remove(2) # no return value, either
# # only the first occurence of 2 is removed
# print(a)
# a.sort() # in ascending order
# print(a) # [1, 3, 4, 5]

# a = a.append(2)
# print(type(a)) # <class 'NoneType'>






# a = [1, 2, [1.1, 2], 'a']

# a[2].remove(2)
# print(a)


# a = [4, 1, 3, 2]

# print(a[::-1]) # slicing(copying sublist)
# print(a)

# a.reverse() # sort() either
# print(a)


# b = 0b11
# print(b)
# c = 0o12
# print(c)
# d = 0x23
# print(d)


# b = 2e-4
# print(type(b)) # e? -> 'float'
# print(b)

# c = 3e3
# print(c)




##### operating 'str' #####




# print('Hello, ' + 'World!')
# print('죄송합니다'*3)


# a = '12345'
# b = '34567'
# print(a[:2] + b[:])


# a = 'abcDEfGhi abc'
# print(a.upper())
# print(a.lower())
# print(a.swapcase())
# print(a.replace('bc', '1')) # successor should be also 'str'
# print(a.capitalize())
# print(a.title())

# a = ['a', 'b', 'c']
# print('#'.join(a))

# a = '  abcd efg   '
# print(a)
# print(a.strip() + '*')
# print(a.lstrip() + '*')
# print(a.rstrip() + '*')

# print(a.index('b')) # index: 'ValueError' in fail // find: -1 in fail



# li = list()
# print(li, type(li))


# li = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# print(li[len(li) - 1]) # len() accepts 'list' either

# li[0] = [1, 2]
# li[1] = type(li[1])
# print(li)




##### <tuple> #####
# (), not modifiable(TypeError)




# tu = tuple()
# print(tu, type(tu))

# tu = (1, 2, 3)
# print(tu[1], tu[:2])


# li = [1, 2, 3]
# tu = 1, 2, (1, 2)
# print(li + li)
# print(tu + tu)




##### <dictionary> #####
# {}, key:value, key is not modifiable




# a = {'key': 'value',
#      1: [1, 2, 3],
#      (1, 2): 'a'}
# print(type(a))
# print(a)

# print(a[1]) # 1 as key
# print(a[(1, 2)])


# d = {'이름': '최명수', '주소': '서울시', '전화': '010-4243-9882'}

# print(d.keys()) # dict_keys(['이름', '주소', '전화'])
# print(d.values()) # dict_values(['최명수', '서울시', '010-4243-9882'])
# print(d.items()) # dict_items([('이름', '최명수'), ('주소', '서울시'), ('전화', '010-4243-9882')])
# # <class 'dict_keys'>, <class 'dict_values'>, <class 'dict_items'>




##### <set> #####
# {}, removes duplicates, no idx




# a = {1, 2, 3, 4, 3}
# print(type(a))
# print(a)



# a = [1, 2, 1, 1, 1, 2, 3, 4, 2, 2, 3, 4, 5, 6, 7, 8, 0, 0, 2]
# a = list(set(a))
# print(a)


# s = 'hello'
# s = set(s)
# print(s)



# s1 = {1, 2, 3, 4, 5, 6}
# s2 = {4, 5, 6, 7, 8, 9}

# print(s1&s2)
# print(s1|s2)
# print(s1 - s2)

# print(s1.intersection(s2))
# print(s2.union(s1))
# print(s2.difference(s1))



# s = {1, 2, 3}

# s.add(4)
# print(s)
# s.remove(2)
# print(s)
# s.update([6, 7]) # should be an iterable object
# print(s)






##### 40p. #####




# T = (1, 2, 3, 4, 5, 6, 7, 8)


# T = list(T)
# T[0] = 0
# print(tuple(T))

# T.append(9)
# print(tuple(T))

# T.remove(8)
# T = tuple(T)
# print(T)




##### 48p. #####




# a = [4, 6, 2, 1, 8, 5, 3, 2, 8, 9, 6]


# a.sort()
# print(a)

# a.reverse()
# print(a)

# a = list(set(a))
# a.reverse() # list[int] automatically sorts the list?
# print(a)




# a = True
# print(type(a)) # <class 'bool'>


# print(bool(0))
# print(bool(2))

# print(bool(0.))
# print(bool(3.14))

# print(bool(''))
# print(bool('False'))

# print(bool([]))
# print(bool(['False']))

# print(bool(tuple()))
# print(bool((0,)))

# print(bool({}))
# print(bool({'False': '거짓'}))

# print(bool(set()))
# print(bool({0}))


# print(0 == 0)
# print(1 != 1)
# print(0 > -1)
# print(1 <= 0)




##### logical operators #####
# and, or, not




# a = True
# b = False

# print(a and b)
# print(a and not b)
# print(a or b)

# a, b = 1, 2
# print(a > 0 and b <= 2)
# print(a == 0 or b != 2)



# print('a' and 'b')
# print('a' and '')
# print('' and 'b')

# print('' or '')
# print('a' or 'b')
# print('' or 'b')




##### conditional statement #####




# score = 59

# if 90 <= score <= 100: # Python supports chained comparison operators
#     print('GOAT')
# if score >= 60 and score < 90:
#     print('Not Bad')
# if score < 60:
#     print('JOAT')


# score = 90

# if score >= 90:
#     print('A')
# elif score >= 80:
#     print('B')
# else:
#     print('JOAT')


# a, b = 1, 2

# if(a == 1):
#     if(b == 1):
#         print('one and one')
#     else:
#         print('only one')
#     print('A1')
# else:
#     print('no one')



# fruit = ['사과', '배', '딸기', '포도']

# if '딸기' in fruit:
#     print("딸기가 있네요~")




##### conditional expression #####




# a = 2
# if(a == 1):
#     msg = 'a is 1'
# else:
#     msg = 'a is not 1'
# print(msg)

# msg2 = 'a is 1' if a == 1 else 'a is not 1' # same as above
# print(msg)




##### for loop #####
# str, list, tuple, dictionary, set, range, dict_keys, dict_values, dict_items, ...




# for i in '1234': # '1234' should be iterable (includes set and dictionary)
#     print(i, end = ' ')
# print()

# for i in range(1, 101, 2): # iterable class 'range' instead of 'int'
#     print(i, end = ' ')
# print()

# for i in range(1, 51):
#     print(2*i - 1, end = ' ')
# print()

# for i in {3, 2, 1}:
#     print(i, end = ' ')
# print()

# profile = {'name': 'Choi Myeongsu', 'address': 'Seoul', 'phone': '01042439882'}
# for i in profile.items():
#     print("%s:   \t%s" % (i[0], i[1]))






# import collections.abc

# print(isinstance(1234, collections.abc.Iterable))
# print(isinstance([1, 2], collections.abc.Iterable))



# for i in [1, 2, 3, 4]:
#     for j in (1, 2, 3, 4):
#         print(j, end = ', ')
#     print(i, end = '-')
# print("\b ")




##### while loop #####




# num = 5 # initialization

# while num > 0: # conditional statement
#     print(num)
#     num -= 1 # decrement




##### input() #####




# a = input("정수를 입력하세요: ")
# a = int(a)

# print(a + a)


# a = int(input("a: "))
# b = int(input("b: "))

# print(f"{a} + {b} = {a + b}")
# print(f"{a} - {b} = {a - b}")
# print(f"{a} * {b} = {a * b}")
# print(f"{a} = {a//b} * {b} + {a%b}")




##### file I/O #####
# open(path, mode), close()




# import os
# print(os.getcwd())


# f = open('D:\\a.txt', 'w')
# f.write('1234')
# f.close()

# f = open('D:\\a.txt', 'a')
# f.write('5678')
# f.close()


# f = open('D:\\a.txt', 'w')
# f.write("내 인생...")
# f.close()

# f = open('D:\\a.txt', 'r')
# print(f.read())
# f.close()




##### function #####
# input -> procedure -> output




# def func():
#     "숫자 1을 출력하는 함수입니다."
#     print(1)

# func()
# help(func)


# def gugu(x = 9): # parameter
#     """비둘기야 먹자~
#     구구단 x단을 출력하는 함수입니다."""
#     for i in range(1, 10):
#         print(f"{x} * {i} = {x*i}")

# gugu(2) # argument
# gugu()
# # (# of parameters) = (# of arguments) unless a parameter has default value


# def func(x, y, z, a, b = 0, c = 1):
#     print(f"x: {x}, y: {y}, z: {z}, a: {a}, b: {b}, c: {c}")

# func(1, 2, 3, 4, 5, 6)
# func(1, 2, 3, 4, 5)
# func(1, 2, 3, 4, c = 5)
# func(1, 2, 3, 4)


# def func():
#     a = 2 # local variable
#     print(a)

# a = 1 # global variable
# func()
# print(a)


# def add(x, y):
#     return x + y

# print(add(3, 5))


# b = [1, 2]

# def func():
#     b = [4, 2]
#     print(b)

# func()
# print(b)






# sum = 0
# for i in range(1, 101):
#     if i%3 == 0:
#         continue
#     sum += i
# print("3의 배수를 제외한 1부터 100까지의 합: %d" % sum)



# print("%d %o %x %.2f %s %c" % (13, 9, 10, 5/3, 'apple', 'A'))


# for i in range(3):
#     for j in range(2):
#         print("중첩 for문입니다. i: %d, j: %d" % (i, j))


# print("%d/%d = %5.1f" % (1, 2, 0.5))


# print("%d" % 123)
# print("%5d" % 123)
# print("%05d" % 123)

# print("%f" % 123.45)

# print("%10s" % 'Python')


# print("{:d} {:5d} {:05d}".format(123, 456, 789))



# print("\nnew line")
# print("\ttab")
# print("\"'\"'\"'")
# print(r"\n \t \" \\ %d")



# def func():
#     pass


# def func(a, *b):
#     print(a)
#     print(b)

# print(func(1, 2, 3))




# import turtle


# t = turtle.Turtle() # create object(instance) t
# t.shape('turtle')
# t.forward(100)

# turtle.exitonclick()


# t = turtle.Turtle()
# t.shape('turtle')
# for i in range(4):
#     t.forward(100)
#     t.right(90)

# turtle.exitonclick()


# t = turtle.Turtle()
# t.shape('turtle')

# t.begin_fill()
# for i in range(5):
#     t.forward(200)
#     t.right(144)
# t.end_fill()

# turtle.exitonclick()


# import sys

# print(sys.builtin_module_names) # standard module list


# import math

# print(dir(math)) # math's attributes


# import calendar

# print(calendar.calendar(2002))


# import time

# print(time.ctime())
# print(time.time())

# for i in range(1, 10):
#     print(i, end = ' ')
#     time.sleep(0.5)
# print(10)


# import time

# word = 'cookie'
# start_time = time.time()
# typed = input("type 'cookie': ")
# end_time = time.time()
# elapsed = end_time - start_time

# if typed == word and end_time - start_time < 3.:
#     print("\nGOAT")
#     print(f"You typed the word within {elapsed:.2f} secs!")
# else:
#     print("\nJOAT")


# import random

# words = ['cookie', 'apple', 'banana']

# print(random.choice(words))
# print(words[random.randint(0, 2)])
# print(words[int(random.random()*3)])


# import random

# words = ['cookie', 'apple', 'banana', 'melon', 'blueberries']

# print(random.choice(words))






##### class #####




# class Car:
#     color = '' # fields
#     speed = 0.

#     def upSpeed(self, val): # methods // self: the parameter used to refer to the fields
#         self.speed += val
#     def downSpeed(self, val):
#         self.speed -= val


# myCar = Car()

# myCar.color = 'red'
# myCar.upSpeed(30.)
# myCar.downSpeed(5.)

# print(f"myCar의 색상은 {myCar.color}이며, 현재 속도는 {myCar.speed}km/h입니다.")



# class Car:
#     color = ''
#     speed = 0.

#     def __init__(self):
#         self.color = 'gray'
#         self.speed = 0.

#     def upSpeed(self, val):
#         self.speed += val
#     def downSpeed(self, val):
#         self.speed -= val


# myCar = Car() # __init__ method(default constructor) call is followed by the declaration(construction)

# print(myCar.color, myCar.speed)



# class Car:
#     color = '' # instance variables
#     speed = 0.

#     def __init__(self, color, speed):
#         self.color = color
#         self.speed = speed
    
#     def upSpeed(self, val):
#         self.speed += val
#     def downSpeed(self, val):
#         self.speed -= val


# myCar1 = Car('red', 30.)
# myCar2 = Car('blue', 60.)

# print(myCar1.color, myCar1.speed) # 2 arguments -> constructor(method)
# print(myCar2.color, myCar2.speed)



# class Car:
#     pass # prevents error




##### class variables #####




# class Car:
#     color = None # instance variables
#     speed = 0.
    
#     cnt = 0

#     def __init__(self, color): # parameterized constructor
#         self.color = color
#         Car.cnt += 1 # (class name).(identifier) for class variables


# myCar1, myCar2 = Car('red'), Car('blue')
# myCar1.speed = 30.
# myCar2.speed = 60.

# print(f"myCar1: {myCar1.color}, {myCar1.speed}km/h")
# print(f"myCar2: {myCar2.color}, {myCar2.speed}km/h")
# print(Car.cnt)




##### method overriding #####




# class Car:
#     speed = 0.

#     def upSpeed(self, val: int):
#         self.speed += val
#         print("current speed(parent class): %.15g" % self.speed)

# class Sedan(Car):
#     def upSpeed(self, val: int): # method overriding(not overload!)
#         self.speed += val

#         if self.speed > 150.:
#             self.speed = 150.
#             print("Please obey the speed limit.")
#         print("current speed(child class): %.15g" % self.speed)

# class Truck(Car):
#     pass # inherited as the super-class


# sedan1, truck1 = None, None # when want to declare only

# sedan1 = Sedan()
# truck1 = Truck()

# sedan1.upSpeed(200)
# truck1.upSpeed(200)



# class Container:
#     value = None

#     def __init__(self, val):
#         self.value = val

#     def print_str(self):
#         print("super duper")

# class IntContainer(Container):
#     def __init__(self, val: int):
#         self.value = val
    
#     def print_str(self):
#         super().print_str()
#         print("sub add")
#         print(super().value)


# box = IntContainer(3)
# box.print_str()




##### special methods #####




# class Line:
#     def __init__(self, length: int):
#         self.length = length
#         print(self.length, "길이의 선이 생성되었습니다.")
    
#     def __del__(self):
#         print(self.length, "길이의 선이 삭제되었습니다.")

#     def __repr__(self):
#         return '선의 길이: ' + str(self.length)
    
#     def __add__(self, other):
#         len1 = self.length
#         len2 = other.length

#         return Line(len1 + len2)

#     def __gt__(self, other):
#         return self.length > other.length
    
#     def __ge__(self, other):
#         return self.length >= other.length
    
#     def __eq__(self, other):
#         return self.length == other.length


# myLine1 = Line(100) # __init__()
# myLine2 = Line(200)

# print(myLine1) # __repr__()
# print(myLine2)

# print(myLine1 != myLine2) # not __eq__()
# print(myLine1 < myLine2) # myLine2's __gt__()
# print(myLine1 >= myLine2) # myLine1's __ge__()

# myLine1 + myLine2 # __add__()
# # __del__()
# del(myLine2)




##### abstract method #####




# class SuperClass:
#     def abstract_method(self): # abstract method
#         pass

# class SubClass1(SuperClass):
#     def abstract_method(self):
#         print("GOAT: hollow knight")

# class SubClass2(SuperClass):
#     pass # will not incur error, but not recommended


# inst = SubClass1()
# inst.abstract_method()

# inst2 = SubClass2()
# inst2.abstract_method()






##### method overloading #####




# class Calculator:
#     def add(self, a: int, b: int, c: int = 0) -> int:
#         """
#         adds three integers
#         """
#         return a + b + c


# cal = Calculator()

# print(cal.add(1, 2))
# print(cal.add(1, 2, 3))




# import multiprocessing

# print(multiprocessing.cpu_count()) # logical processers

# import multiprocessing as mp

# print(mp.cpu_count())

# from multiprocessing import cpu_count

# print(cpu_count())

# from multiprocessing import cpu_count as cc

# print(cc())

# from multiprocessing import * # *: variables, functions, and classes

# print(cpu_count())


# from multiprocessing import cpu_count as cc, current_process as cp

# print(cc())
# print(cp().name)