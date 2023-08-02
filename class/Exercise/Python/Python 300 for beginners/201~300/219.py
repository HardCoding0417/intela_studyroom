def print_arithmetic_operation(a: int, b: int):
    print(f"{a} + {b} = {a + b}")
    print(f"{a} - {b} = {a - b}")
    print(f"{a} * {b} = {a * b}")
    print(f"{a} / {b} = {a / b:.15g}")

print_arithmetic_operation(3, 4)