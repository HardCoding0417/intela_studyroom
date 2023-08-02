from multiprocessing import Process, freeze_support
import time


def worker_function(name: str, delay: float):
    print(f"Worker {name} has started")
    time.sleep(delay)
    print(f"Worker {name} has terminated")


if __name__ == "__main__":
    freeze_support()

    p_cnt = 8
    p_list: list[Process] = []

    for i in range(p_cnt):
        p = Process(target = worker_function, args = (f"p{i}", i*0.1))
        p.start()
        p_list.append(p)

    for i in range(p_cnt):
        p.join()
        p.terminate()
    
    print("All process were terminated")