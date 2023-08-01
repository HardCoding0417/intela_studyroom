N , M = map(int,input().split())
A =[]

def dfs(depth):
    if depth==M:
        for i in A:
           print(i,end=' ')
        print()
        return
    for i in range(1,N+1):
        A.append(i)
        dfs(depth+1)
        A.pop()

dfs(0)