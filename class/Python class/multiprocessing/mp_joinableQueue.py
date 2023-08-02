# We need synchronization to keep the order of printed 'put' and 'got'



from multiprocessing import Process, JoinableQueue, freeze_support
from time import sleep


def worker_func1(j_queue: JoinableQueue, p_name: str) -> None:
    for i in range(10):
        j_queue.put(i)
        print(f"{p_name}: put item {i}")
        sleep(.01)

def worker_func2(j_queue: JoinableQueue, p_name: str) -> None:
    items = []
    
    while True:
        item = j_queue.get()

        if item == None:
            print("All data were transferred")
            j_queue.task_done() # no counter for items in JoinableQueue -> tells that the task is done
            break

        items.append(item)
        print(f"{p_name}: got item {item}")
        j_queue.task_done()


if __name__ == '__main__':
    freeze_support()

    j_queue = JoinableQueue()

    p1 = Process(target = worker_func1, args = (j_queue, 'Process 1'))
    p2 = Process(target = worker_func2, args = (j_queue, 'Process 2'))

    p1.start()
    p2.start()

    p1.join()
    j_queue.put(None)
    p2.join()