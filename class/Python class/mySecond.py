# a = 1 + 2j
# print(type(a)) # <class 'complex'>

# a = 1
# print(type(a)) # <class 'int'>

# a = 1.1
# print(type(a)) # <class 'float'>

# a = '파이썬 이미 시작'
# print(type(a)) # <class 'str'>
# print(a) # 파이썬 이미 시작


# b = "큰따옴표도 문자열"
# print(len(b)) # 9



# x = 3
# print(id(x)) # the address of x


# a = '안녕하세요'

# print(a[0]) # 안
# print(a[-1]) # 요
# print(a[:3]) # 안녕하
# print(a[:]) # 안녕하세요
# print(a[::2]) # 안하요


# a = '1, 2, 3, 4, 5, 6, 7, 8, 9'
# print(len(a)) # 25

# print(a[::3]) # 123456789


# b = '987654321'

# print(b[::-1]) # 123456789




# a = 'abcdabcd'

# print(a.find('b')) # 1
# print(a.replace('c', '??')) # ab??dab??d, but a remains the same before
# print(a.split('d')) # ['abc', 'abc', '']


# help(a.find)
# help(a.replace)
# help(a.split)






# c = 12345
# c = str(c)
# print(type(c)) # <class 'str'>




# print(5 + 3) # 8

# a = 3 - 2
# print(a) # 1

# print(type(9/3)) # 3.0 // <class 'float'>
# print(int(5/3)) # 1.6666666666666667 // 1
# print(5//3) # 1
# print(5%3) # 2
# print(5**3) # 125


# a = 5
# a += 3
# print(a) # 8
# a -= 2
# print(a) # 6

# b = 5
# b **= 3
# print(b) # 125


# print(pow(5, 3)) # 125
# print(divmod(5, 3)) # (1, 2)

# import math

# print(math.sqrt(16)) # 4.0




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


# b = 0B11
# print(b) # 3
# c = 0O12
# print(c) # 10
# d = 0X23
# print(d) # 35


# b = 2e-4
# print(type(b)) # <class 'float'>
# print(b) # 0.0002

# c = 3e3
# print(c) # 3000.0




# print('Hello, ' + 'World!') # Hello, World!
# print('안 죄송해'*3) # 안 죄송해안 죄송해안 죄송해


# a = '12345'
# b = '34567'
# print(a + b[-2:]) # 1234567


# a = 'abcDEfGhi abc'
# print(a.upper()) # ABCDEFGHI ABC
# print(a.lower()) # abcdefghi abc
# print(a.swapcase()) # ABCdeFgHI ABC
# print(a.replace('ab', '100')) # 100cDEfGhi 100c
# print(a.capitalize()) # AbcDEfGhi abc
# print(a.title()) # AbcDEfGhi Abc

# a = ['a', 'b', 'c']
# print('www'.join(a)) # awwwbwwwc

# a = '* * **  *   abcd efg  ** * '
# print(a.strip(' *')) # -abcd efg-
# print(a.lstrip('* ')) # -abcd efg  ** * -
# print(a.rstrip()) # -* * **  *   abcd efg  ** *-

# print(a.index(' ')) # 1
# print(a.find('h')) # -1






# li = list()
# print(li, type(li)) # [] <class 'list'>


# li = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# print(li[len(li) - 1]) # 9


# li[0] = [1, 2]
# li[1] = type(li[1])
# print(li) # [[1, 2], <class 'int'>, 3, ..., 9]




# tu = tuple()
# print(tu, type(tu)) # () <class 'tuple'>

# tu = (1, 2, 3)
# print(tu[1], tu[:2]) # 2 (1, 2)


# li = [1, 2, 3]
# tu = (1, 2, (1, 2))
# print(li + li) # [1, 2, 3, 1, 2, 3]
# print(tu + tu) # (1, 2, (1, 2), 1, 2, (1, 2))




# a = {'key': 'value', 1: [1, 2, 3], (1, 2): 'a'}
# print(type(a)) # <class 'dict'>
# print(a) # {...}

# print(a[1]) # [1, 2, 3]
# print(a[(1, 2)]) # a




# a = {2, 1, 3, 4, 3}
# print(type(a)) # <class 'set'>
# print(a) # {1, 2, 3, 4}


# a = [1, 2, 1, 1, 1, 2, 3, 4, 2, 2, 3, 4, 5, 6, 7, 8, 0, 0, 2]
# a = list(set(a)) # [0, 1, 2, 3, 4, 5, 6, 7, 8]
# print(a)


# s = 'hello'
# s = set(s)
# print(s) # {'h', 'e', 'l', 'o'}



# s1 = {1, 2}
# s2 = {2, 3}

# print(s1&s2) # {2}
# print(s1|s2) # {1, 2, 3}
# print(s1 - s2) # {1}

# print(s2.intersection(s1))
# print(s1.union(s2))
# print(s1.difference(s2))



# s = {1, 2, 3}

# s.add(4) # {1, 2, 3, 4}
# print(s)
# s.remove(2) # {1, 3, 4}
# print(s)
# s.update([3, 5]) # {1, 3, 4, 5}
# print(s)




# a = True
# print(type(a)) # <class 'bool'>


# print(bool(0.)) # False
# print(bool(2.714)) # True
# print(bool({})) # False
# print(bool({'a': 1})) # True


# print(0 == 0) # True
# print(1 != 1) # False
# print(0 > -1) # True
# print(1 <= 0) # False




# a = True
# b = False

# print(a and b) # False
# print(a and not b) # True
# print(a or b) # True



# print('a' and 'b') # b
# print('a' and '') # 
# print('' and 'b') # 

# print('' or '') # 
# print('a' or 'b') # a
# print('' or 'b') # b




# score = 88
# if 90 <= score <= 100:
#     print('A')
# if score >= 80 and score < 90:
#     print('B') # B
# if score >= 70 and score < 80:
#     print('C')


# score = 0.1

# if score >= 90:
#     print('A')
# elif score >= 80:
#     print('B')
# else:
#     print('JOAT')


# a, b = 1, 1

# if(a == 1):
#     if(b == 1):
#         print('one and one')
#     else:
#         print('only one')
#     print('A1')
# else:
#     print('no one')




# a = 1

# msg = 'a is 1' if a == 1 else 'a is not 1'
# print(msg)




# for i in 'abcd':
#     print(i, end = ' ')
# print()

# for i in range(1, 100, 2):
#     print(i, end = ' ')
# print()






# import collections.abc

# print(isinstance({}, collections.abc.Iterable))



# for i in [1, 2, 3, 4]:
#     for j in (1, 2, 3, 4):
#         print(j, end = ', ')
#     print(i, end = '-')
# print('\b ')




# num = 5

# while num > 0:
#     print(num, end = ' ')
#     num -= 1
# print()




# a = input()
# print(a + a) # {a}{a}




# import os

# print(os.getcwd()) # D:\ ... \python class


# f = open('D:\\a.txt', 'w')
# f.write("Why did you open?")
# f.close()

# f = open('D:\\a.txt', 'a')
# f.write("\nClose the notepad ASAP!!!")
# f.write("\n\n3... 2... 1..")
# f.close()

# f = open('D:\\a.txt', 'r')

# while line := f.readline():
#     print(line, end = '')
# print()

# f.close()




# def addd(a, b, c = 0):
#     """
#     add a, b[, and c] then return the result.
#     """
#     return a + b + c

# print(addd(3, 5))
# help(addd)






# print("%d %o %x %f %s %c" % (13, 9, 10, 5/3, 'apple', 'A'))
# # 13 11 a 1.666667 apple A


# print("%05.2f" % 0.5) # 00.50


# print("{0:f} {1:7.2f} {2:06.1f}".format(1.2, 3.4, 5.6))
# # 1.200000    3.40 0005.6



# print(r"%d%f%c%s%x%o\\n\t\a\b\r") # %d%f%c%s%x%o\\n\t\a\b\r



# def func(a, *b, **c):
#     print(a)
#     print(b)
#     print(c)

# func(1, 2, 3, no = 4, way = 5)




# import turtle
# import random

# t = turtle.Turtle()
# t.shape('turtle')
# t.speed(0)

# for i in range(1000):
#     t.forward(random.random()*10)
#     t.right(random.random()*180)

# turtle.exitonclick()


# import sys

# print(sys.builtin_module_names)


# import math

# print(dir(math))






# class Car:
#     color = None
#     speed = 0.

#     produced = 0

#     def __init__(self, color):
#         self.color = color

#         Car.produced += 1
    
#     def upSpeed(self, val):
#         self.speed += val
#     def downSpeed(self, val):
#         self.speed -= val


# myCar1 = Car('red')
# myCar1.upSpeed(30.)
# print(f"Produced: {Car.produced}, color: {myCar1.color}, speed: {myCar1.speed}km/h")
# myCar2 = Car('blue')
# myCar2.downSpeed(40.)
# print(f"Produced: {Car.produced}, color: {myCar2.color}, speed: {myCar2.speed}km/h")




# class Car:
#     speed = 0.

#     def upSpeed(self, val: float):
#         self.speed += val
#         print("부아아아와아아아워ㅏ어어ㅏㅇㅇ")
#     def downSpeed(self, val: float):
#         self.speed -= val

#     def beep(self):
#         pass

# class Sedan(Car):
#     def __init__(self, seat: int):
#         self.seat = seat
    
#     def upSpeed(self, val: float):
#         super().upSpeed(val)
    
#     def beep(self):
#         print("beep!")

# class Truck(Car):
#     carry = 0.

#     def __init__(self, capacity: float):
#         self.capacity = capacity

#     def load(self, load: float):
#         if self.carry + load < self.capacity:
#             self.carry = float("%.15g" % (self.carry + load))
#             self.speed = float("%.15g" % (self.speed*(1. + self.carry/1000)))
#         else:
#             print("load failed")
    
#     def unload(self, unload: float):
#         if self.carry >= unload:
#             self.carry = float("%.15g" % (self.carry - unload))
#         else:
#             print("unload failed")
    
#     def beep(self):
#         print("bread!!!")


# car1 = Sedan(4)
# car1.upSpeed(100)
# print(car1.speed)
# print(car1.seat)
# car1.beep()

# car2 = Truck(1000.)
# car2.upSpeed(60.)
# car2.load(300.)
# print(car2.carry)
# print(car2.speed)
# car2.load(800.)
# car2.unload(400.)
# car2.beep()




# from multiprocessing import Process, freeze_support


# def Hello():
#     print("Hell")


# if __name__ == '__main__':
#     freeze_support()

#     p1 = Process(target = Hello)
    
#     p1.start()
#     p1.join()
#     p1.terminate()



# from multiprocessing import Process, freeze_support


# class HelloProcess(Process):
#     def __init__(self):
#         super(Process, self).__init__()
    
#     def run(self):
#         print("Hell")


# if __name__ == '__main__':
#     freeze_support()

#     p1 = HelloProcess()

#     p1.start()
#     p1.join()
#     p1.terminate()



# from multiprocessing import Process, freeze_support


# def work(num: int):
#     print(f"Process {num} started")


# if __name__ == '__main__':
#     freeze_support()

#     num_process = 8
#     p_list: list[Process] = []

#     for i in range(num_process):
#         p = Process(target = work, args = (i, ))

#         p.start()
#         p_list.append(p)
    
#     for p in p_list:
#         p.join()
    
#     print(f"All {num_process} processes were completed")

#     for p in p_list:
#         p.terminate()






# import multiprocessing
# import time


# def worker_process1(queue: multiprocessing.Queue) -> None:
#     for i in range(100):
#         queue.put(i)
#         time.sleep(.01)

# def worker_process2(queue: multiprocessing.Queue) -> None:
#     items = []

#     while True:
#         item = queue.get(timeout = 1)

#         if item == None:
#             print("All data were transferred")
#             break

#         items.append(item)
#         print(f"pro2: get data {item} from pro1")
#         print(f"data transferred: {items}")


# if __name__ == '__main__':
#     multiprocessing.freeze_support()

#     queue = multiprocessing.Queue()

#     p1 = multiprocessing.Process(target = worker_process1, args = (queue,))
#     p2 = multiprocessing.Process(target = worker_process2, args = (queue,))

#     p1.start()
#     p2.start()

#     p1.join()
#     queue.put(None)
#     p2.join()




# from multiprocessing import Process, SimpleQueue, freeze_support
# import time


# def working_func1(s_queue: SimpleQueue):
#     for i in range(10):
#         s_queue.put(i)
#         print(f"Process 1: put item {i}")
#         time.sleep(0.01)

# def working_func2(s_queue: SimpleQueue):
#     items = []

#     while True:
#         item = s_queue.get()

#         if item == None:
#             print("All data were transferred")
#             break

#         items.append(item)
#         print(f"Process 2: got item {item}")
#         print(f"Process 2: received items {items}")


# if __name__ == '__main__':
#     freeze_support()

#     s_queue = SimpleQueue()

#     p1 = Process(target = working_func1, args = (s_queue,))
#     p2 = Process(target = working_func2, args = (s_queue,))

#     p1.start()
#     p2.start()

#     p1.join()
#     s_queue.put(None)
#     p2.join()






# from multiprocessing import Process, JoinableQueue, freeze_support
# from time import sleep


# def worker_func1(j_queue: JoinableQueue, p_name: str) -> None:
#     for i in range(10):
#         j_queue.put(i)
#         print(f"{p_name}: put item {i}")


# def worker_func2(j_queue: JoinableQueue, p_name: str) -> None:
#     items = []

#     while True:
#         item = j_queue.get()

#         if item == None:
#             print("All data were transferred")
#             print("transferred items:", items)
#             j_queue.task_done()

#             break

#         items.append(item)
#         print(f"{p_name}: got item {item}")



# if __name__ == '__main__':
#     freeze_support()

#     j_queue = JoinableQueue()

#     p1 = Process(target = worker_func1, args = (j_queue, 'Process 1'))
#     p2 = Process(target = worker_func2, args = (j_queue, 'Process 2'))

#     p1.start()
#     p2.start()

#     p1.join()
#     j_queue.put(None)
#     p2.join()



# from multiprocessing import Process, Value, freeze_support
# import time


# def worker_func1(shared_val: Value, p_name: str) -> None:
#     print(f"{p_name}: initial value of shared_val {shared_val.value}")

# def worker_func2(shared_val: Value, p_name: str) -> None:
#     time.sleep(.1)
#     shared_val.value = 1
#     print(f"{p_name}: changed value of shared_val {shared_val.value}")


# if __name__ == '__main__':
#     freeze_support()

#     shared_val = Value('i')

#     p1 = Process(target = worker_func1, args = (shared_val, 'Process 1'))
#     p2 = Process(target = worker_func2, args = (shared_val, 'Process 2'))

#     p1.start()
#     p2.start()

#     p1.join()
#     p2.join()



# from multiprocessing import Process, Manager, freeze_support
# import time


# def worker_func1(manager_list, p_name: str) -> None:
#     manager_list.append(p_name)
#     print(f"{p_name}: modified manager_list - {manager_list}")

# def worker_func2(manager_list, p_name: str) -> None:
#     time.sleep(.01)
#     manager_list.append(p_name)
#     print(f"{p_name}: modified manager_list - {manager_list}")


# if __name__ == '__main__':
#     freeze_support()

#     manager = Manager()
#     manager_list = manager.list()

#     p1 = Process(target = worker_func1, args = (manager_list, 'Process1'))
#     p2 = Process(target = worker_func2, args = (manager_list, 'Process2'))

#     p1.start()
#     p2.start()

#     p1.join()
#     p2.join()



# import multiprocessing
# import time


# def worker_func1(event: multiprocessing.Event) -> None:
#     event.wait()
#     time.sleep(.01)
#     print('와')

# def worker_func2(event: multiprocessing.Event) -> None:
#     event.wait()
#     print('우', end = '')


# if __name__ == '__main__':
#     multiprocessing.freeze_support()

#     event = multiprocessing.Event()

#     p1 = multiprocessing.Process(target = worker_func1, args = (event,))
#     p2 = multiprocessing.Process(target = worker_func2, args = (event,))

#     p1.start()
#     p2.start()

#     time.sleep(.5)
#     event.set()

#     p1.join()
#     p2.join()