from multiprocessing import Process, freeze_support


class HelloProcess(Process): # inherited
    def __init__(self):
        super(Process, self).__init__()
    
    def run(self):
        print("Hello, Process")


if __name__ == '__main__':
    freeze_support()

    p1 = HelloProcess()
    p1.start() # invokes p1.run()
    p1.join()
    p1.terminate() # not to make it zombie