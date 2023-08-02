from multiprocessing import Process, freeze_support # for Windows


def Hello():
    print("Hello, Process!")


if __name__ == '__main__': # startpoint of the script
    # only if the script is run directly
    freeze_support()
    # On Windows, frozen executable file will not work unless there is 'freeze_support()'

    p1 = Process(target = Hello) # create an Process object to run 'Hello' function
    p1.start()
    p1.join() # wait until the process ends
    p1.terminate()