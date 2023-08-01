# Condition() for process synchronization



# import multiprocessing
# import time


# def worker_func1(condition: multiprocessing.Condition, process_name: str) -> None: # p1, p2
#     condition.acquire()
    
#     condition.wait() # wait until certain condition
#     print(f"{process_name}: 오랜 기다림이 끝났다...")

#     condition.release()

# def worker_func2(condition: multiprocessing.Condition, process_name: str) -> None: # p3
#     condition.acquire()

#     # condition.notify() # p1 or p2
#     condition.notify_all()
#     print(f"{process_name}: 내가 너희들을 깨웠다...")

#     condition.release()    


# if __name__ == '__main__':
#     multiprocessing.freeze_support()

#     condition = multiprocessing.Condition()
    
#     p1 = multiprocessing.Process(target = worker_func1, args = (condition, 'Process 1'))
#     p2 = multiprocessing.Process(target = worker_func1, args = (condition, 'Process 2'))
#     p3 = multiprocessing.Process(target = worker_func2, args = (condition, 'Process 3'))

#     p1.start()
#     p2.start()
#     time.sleep(.1)
#     p3.start()

#     p1.join()
#     p2.join()
#     p3.join()



import multiprocessing
import time


def worker_func(condition: multiprocessing.Condition, process_name: str) -> None:
    with condition: # condition.acquire(), condition.release()
        condition.wait()
        print(f"{process_name}: Worker process started")

if __name__ == '__main__':
    multiprocessing.freeze_support()

    condition = multiprocessing.Condition()

    p1 = multiprocessing.Process(target = worker_func, name = 'Process 1', args = (condition, 'Process 1'))
    p2 = multiprocessing.Process(target = worker_func, name = 'Process 2', args = (condition, 'Process 2'))

    p1.start()
    p2.start()
    
    print(multiprocessing.active_children())

    time.sleep(.1)
    with condition:
        condition.notify_all()
        print(f"MainProcess: notified all processes")

    p1.join()
    p2.join()

    print("All processes were completed")