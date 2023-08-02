def print_5xn(string: str):
    for i in range((len(string) + 4)//5):
        print(string[5*i:5*i + 5])

print_5xn("아이엠어보이유알어걸유언더스텐드?")