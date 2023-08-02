import sys
input = sys.stdin.readline
N = int(input())
row = [0]*15
result=0
def possible(col):
    for i in range(col):
        if row[col] == row[i] or col - i ==abs(row[col]-row[i]):
            return False
    return True
    
def dfs(depth):
    global result
    if depth==N:
        result+=1
        return
    for i in range(N):
        row[depth]=i
        if possible(depth):
            dfs(depth+1)
dfs(0)
print(result)

