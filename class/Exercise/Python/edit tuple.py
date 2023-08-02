# T = (1, 2, 3, 4, 5, 6, 7, 8)


# idx = T.index(1)
# T = T[:idx] + (0,) + T[idx + 1:]

# T += (9,)

# idx = T.index(8)
# T = T[:idx] + T[idx + 1:]



T = (1, 2, 3, 4, 5, 6, 7, 8)


L = list(T)
L[L.index(1)] = 0
T = tuple(L)

T += (9,)

L = list(T)
L.remove(8)
T = tuple(L)