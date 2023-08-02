def some_func() -> None:
    print("This print() is in a function in the module.")


if __name__ == '__main__':
    print("This print() is excuted at global level?")
    some_func()