def star(N):
    if N==1:
        return ['*']
    pre = star(N//3)
    
    A =[ i + i + i for i in pre]
    B =[ i + ' '*(N//3) + i for i in pre]
    C = [ i + i + i for i in pre]
    return A+B+C
N = int(input())
for i in star(N):
    print(i)