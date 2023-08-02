def merge_sort(arr: list) -> None:
    merge_sort_r(arr, 0, len(arr))

def merge_sort_r(arr: list, l: int, r: int) -> None:
    if l + 1 >= r:
        return
    
    merge_sort_r(arr, l, (l + r)//2)
    merge_sort_r(arr, (l + r)//2, r)

    merge(arr, l, (l + r)//2, r)


def merge(arr: list, l: int, mid: int, r: int) -> None:
    arr1 = arr[l:mid]
    arr2 = arr[mid:r]

    idx = l 
    l1, l2 = 0, 0
    r1, r2 = mid - l, r - mid
    while l1 < r1 and l2 < r2:
        if arr1[l1] <= arr2[l2]:
            arr[idx] = arr1[l1]
            l1 += 1
        else:
            arr[idx] = arr2[l2]
            l2 += 1
        idx += 1
    while l1 < r1:
        arr[idx] = arr1[l1]
        l1 += 1
        idx += 1
    while l2 < r2:
        arr[idx] = arr2[l2]
        l2 += 1
        idx += 1



import random


list = [random.randint(0, 100) for i in range(500)]

merge_sort(list)
print(list)