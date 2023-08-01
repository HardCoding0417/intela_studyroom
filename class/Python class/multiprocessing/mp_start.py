##### how to start process #####
# spawn         : with code                             ex] Windows, Linux, Mac OS
# fork          : clone parent process                  ex] Linux, Mac OS (heavy for copying Windows GUI)
    # create processes fast
# forkserver    : create process from center server     ex] Linux



import multiprocessing


def start_process() -> int:
    return 1


if __name__ == '__main__':
    multiprocessing.freeze_support()

    print(multiprocessing.get_start_method())
    # spawn process by default
    multiprocessing.set_start_method('spawn')
    # if Linux and wanna change the way to create process
    # multiprocessing.set_start_method('forkserver')
    # only in Linux

    p1 = multiprocessing.Process(target = start_process)

    p1.start()
    p1.join()
    p1.terminate()




# Creates 4 distinct processes by function



# import multiprocessing


# def worker_process(name):
#     print(f"Worker process {name} started")


# if __name__ == '__main__':
#     multiprocessing.freeze_support()

#     num_process = 4 # number of processes to create
#     processes: list[multiprocessing.Process] = []

#     for i in range(num_process):
#         p = multiprocessing.Process(target = worker_process, args = (i,))
#         p.start()
        
#         processes.append(p)

#     for p in processes:
#         p.join()
    
#     print(f"All the {num_process} processes were completed")

#     for p in processes:
#         p.terminate()