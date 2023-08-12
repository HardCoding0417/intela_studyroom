import sys
input = sys.stdin.readline

N , K = map(int,input().split())
count=0
ans =0
A = list(map(int,input().split()))

def merge(A,S,mid,E):
    global count,ans
    pre= count
    count+=E-S+1
    if count>=K:
        temp=A[S:E+1]
        temp.sort()
        ans=temp[-(count-K+1)]
        print(ans)
        exit()
def merge_sort(A,S,E):
    if S==E:
        return
    mid = (S+E)//2
    merge_sort(A,S,mid)
    merge_sort(A,mid+1,E)
    merge(A,S,mid,E)

merge_sort(A,0,N-1)
if ans==0:
    print("-1")
else:
    print(ans)