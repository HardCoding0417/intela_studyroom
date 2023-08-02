from multiprocessing import Process, SimpleQueue, freeze_support
import time


def worker_func1(s_queue: SimpleQueue):
    for i in range(10):
        s_queue.put(i)
        print(f"Process 1: put {i} in the simple queue")

def worker_func2(s_queue: SimpleQueue):
    items = []
    
    while True:
        item = s_queue.get()

        if item == None:
            print("\nAll data were transferred")
            break

        items.append(item)
        print(f"Process 2: got new item {item} from the simple queue")
        print(f"Process 2: received items {items}")


if __name__ == '__main__':
    freeze_support()

    s_queue = SimpleQueue()

    p1 = Process(target = worker_func1, args = (s_queue,))
    p2 = Process(target = worker_func2, args = (s_queue,))

    p1.start()
    p2.start()

    p1.join()
    s_queue.put(None)
    p2.join()