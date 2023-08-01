import sys
input = sys.stdin.readline
N = int(input())
S = set()
ans=0
for _ in range(N):
    temp = input()[:-1]
    if temp=="ENTER":
        ans+=len(S)
        S.clear()
    else:
        S.add(temp)
ans+=len(S)
print(ans)