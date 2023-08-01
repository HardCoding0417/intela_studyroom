def print_value_by_key(ohlc_dict: dict, date: str):
    print(ohlc_dict[date])


my_dict = {"10/26": [100, 130, 100, 100],
           "10/27": [10, 12, 10, 11]}

print_value_by_key(my_dict, "10/26")