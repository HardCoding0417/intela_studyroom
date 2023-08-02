N = int(input())
A =[]
for _ in range(N):
    temp = list(map(int,input().split()))
    A.append(temp)
visited = [False] * N
Team = [0]
S = set(range(N))
ans =[]
def dfs(depth,next):
    if depth == N//2-1:
        dTeam= list(S-set(Team))
        s1 =0
        s2 =0
        for i in range(N//2):
            for j in range(N//2):
                s1+=A[Team[i]][Team[j]]
        for i in range(N//2):
            for j in range(N//2):
                s2+=A[dTeam[i]][dTeam[j]]
        ans.append(abs(s1-s2))
        return
    
    for i in range(next,N):
        if not visited[i]:
            visited[i]=True
            Team.append(i)
            dfs(depth+1,i+1)
            Team.pop()
            visited[i]=False
dfs(0,1)
print(min(ans))