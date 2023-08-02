def pickup_even(num_list: list):
    res = []
    for num in num_list:
        if num%2 == 0:
            res.append(num)
    
    return res

print(pickup_even([3, 4, 5, 6, 7, 8]))