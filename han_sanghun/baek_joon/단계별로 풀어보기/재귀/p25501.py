import sys
input = sys.stdin.readline
print = sys.stdout.write
T = int(input())
ans = 0
def recursion(s,l,r):
    global ans
    ans+=1
    if l >= r: return 1
    elif s[l]!=s[r]: return 0
    else: return recursion(s,l+1,r-1)
for _ in range(T):
    P = input().rstrip()
    ans=0
    print(str(recursion(P,0,len(P)-1))+' ')
    print(str(ans)+'\n')


