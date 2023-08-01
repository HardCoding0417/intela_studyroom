s=input().upper()
l=len(s)
c=[0 for x in range(26)]
for j in range(l):
    a=ord(s[j])-65
    c[a]+=1
f=0
m=0
for j in range(26):
    t=c[j]
    if t==m:
        f=0
    if t>m:
        m=t
        i=j
        f=1
if f:
    print(chr(i+65))
else:
    print("?")