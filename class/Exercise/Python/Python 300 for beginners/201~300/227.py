def printmxn(string: str, cnt: int):
    for i in range((len(string) - 1 + cnt)//cnt):
        print(string[cnt*i:cnt*i + cnt])

printmxn("아이엠어보이유알어걸얼유언더스텐드?", 10)