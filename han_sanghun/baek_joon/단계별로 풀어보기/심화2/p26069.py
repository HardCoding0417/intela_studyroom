N = int(input())
S ={'ChongChong'}
for _ in range(N):
    A = input().split()
    if A[0] in S:
        S.add(A[1])
    if A[1] in S:
        S.add(A[0])

print(len(S))