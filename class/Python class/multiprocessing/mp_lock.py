# Lock() to allow only one processer to access the shared data



import multiprocessing
import time


def worker_func1(shared_val: multiprocessing.Value, lock: multiprocessing.Lock) -> None:
    lock.acquire()

    while shared_val.value < 10:
        print(f"now {shared_val.value}")
        shared_val.value += 1
        time.sleep(.01001)

    lock.release()

def worker_func2(shared_val: multiprocessing.Value, lock: multiprocessing.Lock) -> None:
    lock.acquire()

    while shared_val.value > -10:
        print(f"now {shared_val.value}")
        shared_val.value -= 1
        time.sleep(.01)

    lock.release()


if __name__ == '__main__':
    multiprocessing.freeze_support()

    shared_val = multiprocessing.Value('i', 0)
    lock = multiprocessing.Lock() # for access control to shared data

    p1 = multiprocessing.Process(target = worker_func1, args = (shared_val, lock))
    p2 = multiprocessing.Process(target = worker_func2, args = (shared_val, lock))

    p1.start()
    p2.start()

    p1.join()
    p2.join()