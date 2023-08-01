# Barrier(): gather processes and run simultaneously



import multiprocessing
import time


def worker_func1(barrier: multiprocessing.Barrier, process_name: str) -> None:
    print(f"{process_name}: 멈춰!")
    barrier.wait()
    print(f"{process_name}: 싫어!")


def worker_func2(barrier: multiprocessing.Barrier, process_name: str) -> None:
    barrier.wait()
    print(f"{process_name}: 싫어!")


if __name__ == '__main__':
    multiprocessing.freeze_support()

    barrier = multiprocessing.Barrier(2)
    
    p1 = multiprocessing.Process(target = worker_func1, args = (barrier, 'Process 1'))
    p2 = multiprocessing.Process(target = worker_func2, args = (barrier, 'Process 2'))

    p1.start()
    time.sleep(.5)
    p2.start()

    p1.join()
    p2.join()