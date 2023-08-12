import sys
sys.setrecursionlimit(10**8)
K=0
A = []
def move(n,start,end):
    global K
    K+=1
    A.append((start,end))
    

def hanoi(n,start,end,mid):
    if n==1:
        move(n,start,end)
        return
    hanoi(n-1,start,mid,end)
    move(n,start,end)
    hanoi(n-1,mid,end,start)

N = int(input())
hanoi(N,1,3,2)
print(K)
for i in A:
    print(i[0],i[1])
