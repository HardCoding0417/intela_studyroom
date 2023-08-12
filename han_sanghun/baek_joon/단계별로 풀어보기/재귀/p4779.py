def kan(N):
    if N==0:
        return '-'
    pre = kan(N-1)
    
    return [i+' '*(3**(N-1))+i for i in pre]

while True:
   try: 
        N = int(input())
        print(kan(N)[0])
   except EOFError:
       break