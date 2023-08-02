import os
import time


script1 = '정말 아름다운 날이야.\n새들은 지저귀고, 꽃들은 피어나고...\n이런 날엔, 너 같은 꼬마들은...\n'
script2 = '지옥에서 불타고 있어야 하는데.'

for i in range(len(script1)):
    print(script1[i], end = '')
    time.sleep(0.13)
    
    if script1[i] == '\n':
        time.sleep(1.5)

time.sleep(0.8)
os.system('cls')
time.sleep(0.3)
for i in range(len(script2)):
    print(script2[i], end = '')
    time.sleep(0.2)
time.sleep(1)
os.system('cls')