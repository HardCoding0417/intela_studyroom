import sys
input = sys.stdin.readline
N = int(input())
A =[]
CP = [0 for _ in range(4001)]
CN = [0 for _ in range(4001)]
for _ in range(N):
    temp = int(input())
    A.append(temp)
    if temp>=0:
        CP[temp]+=1
    else:
        CN[abs(temp)]+=1

print(round(sum(A)/len(A)))
A.sort()
print(A[N//2])
f = max(max(CP),max(CN))
fl =[]
for i in range(0,4001):
    if CP[i]==f:
        fl.append(i)
    if CN[i]==f:
        fl.append(-i)
fl.sort()
if len(fl)==1:
    print(fl[0])
else:
    print(fl[1])
print(A[-1]-A[0])