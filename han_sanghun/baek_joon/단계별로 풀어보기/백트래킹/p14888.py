from collections import deque

N = int(input())
A = list(map(int,input().split()))
op = list(map(int,input().split()))
ans = []
C = [" "]*(N-1)
def dfs(depth):
    if depth==N-1:
        q = deque(A)
        for i in range(N-1):
            a = q.popleft()
            b = q.popleft()
            if C[i]=='+':
                q.appendleft(a+b)
            elif C[i]=='-':
                q.appendleft(a-b)
            elif C[i]=='*':
                q.appendleft(a*b)
            elif C[i]=='/':
                if (a<0 and b>0):
                    q.appendleft(-(-a//b))
                else:
                    q.appendleft(a//b)
        ans.append(q[0])
        return
    
    for i in range(4):
        if op[i]>0:
            op[i]-=1
            if i==0:
                C[depth]="+"
            elif i ==1:
                C[depth]="-"
            elif i ==2:
                C[depth]="*"
            elif i==3:
                C[depth]="/"
            dfs(depth+1)
            op[i]+=1
dfs(0)
print(max(ans))
print(min(ans))
        