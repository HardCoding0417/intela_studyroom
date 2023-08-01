dp = [[0 for col in range(31)] for row in range(31)]
dp[1][1]=1
dp[1][0]=1
def C(N,R):
    global dp
    if N<R:
        return 0
    if R==1:
        return N
    if dp[N][R]!=0:
        return dp[N][R]
    dp[N][R]=C(N-1,R-1)+C(N-1,R)
    return dp[N][R]
T = int(input())
for _ in range(T):
    N,M = map(int, input().split())
    print(C(M,N))