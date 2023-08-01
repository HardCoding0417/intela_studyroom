# Event() - for process synchronization
# ex] run two processes at the same time after 3 secs.



import multiprocessing
import time


def worker_func1(event: multiprocessing.Event) -> None:
    event.wait() # wait until event is set
                 # if set, wait() returns
    print("Process 1")

def worker_func2(event: multiprocessing.Event) -> None:
    event.wait()
    print("Process 2")


if __name__ == '__main__':
    multiprocessing.freeze_support()

    event = multiprocessing.Event()

    p1 = multiprocessing.Process(target = worker_func1, args = (event,))
    p2 = multiprocessing.Process(target = worker_func2, args = (event,))

    p1.start()
    p2.start()

    time.sleep(1)
    event.set()

    p1.join()
    p2.join()