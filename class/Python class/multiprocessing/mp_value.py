# typecode(array) for Value()
# i, f, c, u, b, ...



from multiprocessing import Process, Value, freeze_support
import time


def worker_func1(pub_val: Value, p_name: str) -> None:
    print(f"{p_name}: initial value {pub_val.value}")


def worker_func2(pub_val: Value, p_name: str) -> None:
    time.sleep(.00001)
    pub_val.value = 10
    print(f"{p_name}: changed value {pub_val.value}")


if __name__ == '__main__':
    freeze_support()

    pub_val = Value('i') # i for integer / default 0

    p1 = Process(target = worker_func1, args = (pub_val, 'Process 1'))
    p2 = Process(target = worker_func2, args = (pub_val, 'Process 2'))

    p1.start()
    p2.start()

    p1.join()
    p2.join()