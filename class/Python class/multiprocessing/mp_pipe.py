# Pipe() shares data, based on RAM -> could be limited by system's physical memory
# Thus, Queue() and Manager() are suitable for large data sharing rather than Pipe()


import multiprocessing


def worker_func1(pipe_sender: multiprocessing.Pipe) -> None:
    pipe_sender.send('1234')
    print("sent data")

def worker_func2(pipe_receiver: multiprocessing.Pipe) -> None:
    item = pipe_receiver.recv()
    print(f"received data {item}")


if __name__ == '__main__':
    multiprocessing.freeze_support()

    pipe_sender, pipe_receiver = multiprocessing.Pipe()

    p1 = multiprocessing.Process(target = worker_func1, args = (pipe_sender,))
    p2 = multiprocessing.Process(target = worker_func2, args = (pipe_receiver,))

    p1.start()
    p2.start()

    parent_process = multiprocessing.current_process()
    print(f"current process: {parent_process}")
    print(f"current process name: {parent_process.name}")
    print(f"current process ID: {parent_process.pid}\n")

    child_processes = multiprocessing.active_children()
    for process in child_processes:
        print(f"Process: {process}")
        print(f"Name: {process.name}\tPID: {process.pid}")
    print()
    
    p1.join()
    p2.join()