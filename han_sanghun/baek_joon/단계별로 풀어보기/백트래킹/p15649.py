N,M = map(int,input().split())
visited =[False for _ in range(N+1)]
A =[]
def dfs(depth):
    if depth==M:
        for i in A:
            print(i,end=' ')
        print()
        return
    for i in range(1,N+1):
        if not visited[i]:
            visited[i]=True
            A.append(i)
            dfs(depth+1)
            A.pop()
            visited[i]=False

dfs(0)