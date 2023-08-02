import multiprocessing
import time


TIME_SLEEP = .1


class WorkerProcess1(multiprocessing.Process):
    def __init__(self, value_obj: multiprocessing.Value, lock: multiprocessing.Lock,
                 process_name: str) -> None:
        super(WorkerProcess1, self).__init__()
        self.shared_val = value_obj
        self.lock = lock
        self.process_name = process_name
    
    def run(self) -> None:
        self.lock.acquire()

        while self.shared_val.value < 10:
            print(f"{self.process_name}: shared value {self.shared_val.value}")
            self.shared_val.value += 1
            time.sleep(TIME_SLEEP)

        self.lock.release()

class WorkerProcess2(multiprocessing.Process):
    def __init__(self, value_obj: multiprocessing.Value, lock: multiprocessing.Lock,
                 process_name: str) -> None:
        super(WorkerProcess2, self).__init__()
        self.shared_val = value_obj
        self.lock = lock
        self.process_name = process_name
    
    def run(self) -> None:
        self.lock.acquire()

        while self.shared_val.value > -10:
            print(f"{self.process_name}: shared value {self.shared_val.value}")
            self.shared_val.value -= 1
            time.sleep(TIME_SLEEP)
        
        self.lock.release()


if __name__ == '__main__':
    multiprocessing.freeze_support()

    val_obj = multiprocessing.Value('i', 0)
    lock = multiprocessing.Lock()

    p1 = WorkerProcess1(val_obj, lock, 'Process 1')
    p2 = WorkerProcess2(val_obj, lock, 'Process 2')
    p3 = WorkerProcess1(val_obj, lock, 'Process 3')
    p4 = WorkerProcess2(val_obj, lock, 'Process 4')

    p1.start(); p2.start(); p3.start(); p4.start()
    p1.join(); p2.join(); p3.join(); p4.join()