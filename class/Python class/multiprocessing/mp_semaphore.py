# Semaphore(): limit the number of processes -> internal counter



# import multiprocessing
# import time


# def worker_func1(semaphore: multiprocessing.Semaphore, process_name: str) -> None:
#     with semaphore:
#         print(f"{process_name}: process started")
#         time.sleep(.5)
#     print(f"{process_name}: released semaphore")

# def worker_func2(semaphore: multiprocessing.Semaphore, process_name: str) -> None:
#     with semaphore:
#         print(f"{process_name}: process started")
#         time.sleep(.5)
#     print(f"{process_name}: released semaphore")


# if __name__ == '__main__':
#     multiprocessing.freeze_support()

#     semaphore = multiprocessing.Semaphore(1) # max number of running process

#     p1 = multiprocessing.Process(target = worker_func1, name = 'Process 1',
#                                  args = (semaphore, 'Process 1'))
#     p2 = multiprocessing.Process(target = worker_func2, name = 'Process 2',
#                                  args = (semaphore, 'Process 2'))

#     p1.start()
#     p2.start()

#     p1.join()
#     p2.join()   



import multiprocessing
import time


def worker_func(semaphore: multiprocessing.Semaphore, process_idx: int) -> None:
    with semaphore:
        print(f"Process {process_idx} started")
        time.sleep(.5)
        print(f"Process {process_idx} completed")
    print(f"Process {process_idx} released semaphore")


if __name__ == '__main__':
    multiprocessing.freeze_support()

    semaphore = multiprocessing.Semaphore(2)

    processes: list[multiprocessing.Process] = []
    for i in range(4):
        process = multiprocessing.Process(target = worker_func, args = (semaphore, i))
        process.start()
        processes.append(process)
    
    for process in processes:
        process.join()

    print("\nAll processes were terminated")