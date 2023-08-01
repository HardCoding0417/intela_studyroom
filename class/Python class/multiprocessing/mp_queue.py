# share object between processes: multiprocessing.Queue




from multiprocessing import Process, Queue, freeze_support
import time


def pro1(queue: Queue):
    for i in range(100):
        queue.put(i)
        time.sleep(.01)

def pro2(queue: Queue):
    items = []

    while True:
        item = queue.get(timeout = 1) # wait until it gets item

        if item == None:
            print("All data were transfered")
            break

        items.append(item)
        print(f"pro2: has brought {item} from pro1")
        print(f"pro2: now has {items}")


if __name__ == '__main__':
    freeze_support()

    queue = Queue()

    p1 = Process(target = pro1, args = (queue,))
    p2 = Process(target = pro2, args = (queue,))

    p1.start()
    p2.start()

    p1.join()
    queue.put(None)
    p2.join()