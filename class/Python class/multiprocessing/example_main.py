import example_module as em


def main_func() -> None:
    print("This print() is in a function in the main script")


if __name__ == '__main__':
    print("This print() is in the main script")

    main_func()
    em.some_func()