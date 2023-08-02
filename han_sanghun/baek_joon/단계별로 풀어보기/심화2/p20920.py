import sys
input = sys.stdin.readline
print = sys.stdout.write
N, M = map(int,input().split())
D = {}
A =[]
for _ in range(N):
    temp = input()[:-1]
    if len(temp)<M:
        continue
    if temp in D:
        D[temp]+=1
    else:
        D[temp]=1
        A.append(temp)
A.sort(key=lambda x : (-D[x],-len(x),x))
for i in A:
    print(i+'\n')