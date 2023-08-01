A =[]
zero =[]
d = {}
for _ in range(9):
    temp = list(map(int,input().split()))
    A.append(temp)
for x in range(9):
    for y in range(9):
        if A[x][y]==0:
            zero.append((x,y))
for i in range(0,9,3):
    for j in range(0,9,3):
        for k in range(3):
            for l in range(3):
                d[(i+k,j+l)]=(i,j)

def possible(depth,v):
    x,y = zero[depth]
    for i in range(9):
        if A[i][y]==v:
            return False
    for i in range(9):
        if A[x][i]==v:
            return False
    a,b = d[(x,y)]
    for i in range(a,a+3):
        for j in range(b,b+3):
            if A[i][j]==v:
                return False    
    return True
    



def dfs(depth):
    if depth == len(zero):
        for i in range(9):
            for j in range(9):
                print(A[i][j],end=" ")
            print()
        exit(0)
    x , y = zero[depth]
    for i in range(1,10):
        if possible(depth,i):
            A[x][y] = i
            dfs(depth+1)
            A[x][y] = 0
dfs(0)