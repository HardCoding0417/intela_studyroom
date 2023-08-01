def convert_int(string: str):
    return int(string.replace(',', ''))

print(convert_int("1,234,567"))