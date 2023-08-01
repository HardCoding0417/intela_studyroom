N, K = map(int,input().split())
a = 1
b = 1
for i in range(N-K+1,N+1):
    a*=i
for i in range(1,K+1):
    b*=i
print(a//b)