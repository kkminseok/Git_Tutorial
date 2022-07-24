from collections import deque
import math


maxx,maxy,k = map(int,input().split())
result = 0

lt1 = deque()
lt2 = deque()

check = deque()

for x in range(maxx+1):
    for y in range(maxy+1):
        # row col 처리 구문
        lt1.append([x,y])
        lt2.append([x,y])

for i in range(1,k) : 
    check.append(pow(i,2))
#print(check)

for idx in range(len(lt1)) : 
    for idj in range(idx+1,len(lt2)) : 
        x1,y1 = lt1[idx]
        x2,y2 = lt2[idj]
        res = pow(x2-x1,2) + pow(y2-y1,2)
        if y1 == y2 or x1 == x2:
            if res == pow(k-1,2) : 
                #print("ok",x1,x2,y1,y2)
                result+= 1
        else : 
            #print("res", res)
            if res == (pow(k-1,2) * 2) : 
                result+=1 
print(result)