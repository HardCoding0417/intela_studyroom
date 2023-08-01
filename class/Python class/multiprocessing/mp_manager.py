from multiprocessing import Process, Manager, freeze_support
import time


def worker_func1(manager_list: Manager, p_name: str) -> None:
    manager_list.append(p_name)
    print(manager_list)

def worker_func2(manager_list: Manager, p_name: str) -> None:
    time.sleep(.01)
    manager_list.append(p_name)
    print(manager_list)


if __name__ == '__main__':
    freeze_support()

    manager = Manager()
    manager_list = manager.list() # or manager.dict()
    print(f"initial value of manager_list: {manager_list}")

    p1 = Process(target = worker_func1, args = (manager_list, 'Process 1'))
    p2 = Process(target = worker_func2, args = (manager_list, 'Process 2'))

    p1.start()
    p2.start()

    p1.join()
    p2.join()