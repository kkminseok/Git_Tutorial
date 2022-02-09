import sys
from collections import deque

tomato = []

N,M,H = map(int,input().split())

dq = deque()

for depth in range(H) : 
    tomato.append([])
    for col in range(M) :
        tomato[depth].append(list(map(int,sys.stdin.readline().split())))
            

# depth, col, row 순임.

check = [[[0 for col in range(N)]for row in range(M)] for depth in range(H)]

day = 0
tempdq = deque()

dx =[-1,0,1,0,0,0]
dy =[0,1,0,-1,0,0]
dz = [0,0,0,0,1,-1]

#초기 체크


tocount = 0 

for depth in range(H) :
    for row in range(M) : 
        for col in range(N) : 
            #print(depth,row,col,M,N)
            if tomato[depth][row][col] == 1: 
                check[depth][row][col] = 1
                dq.append((depth,row,col,0))
            elif tomato[depth][row][col] == 0 :
                tocount += 1
#print(dq)

while dq : 
    d,r,c,counting = dq.popleft()
    #print(d,r,c,counting)
    
    for k in range(len(dz)) :
        newr,newc,newd = dx[k] + r,dy[k] + c,dz[k] + d
        if 0<= newd and newd < H and 0<=newr and newr<M and 0<=newc and newc < N :
            if check[newd][newr][newc] == 0 and tomato[newd][newr][newc] == 0 :
                if tomato[newd][newr][newc] == 0 :
                    tocount-=1
                tempdq.append((newd,newr,newc))
                dq.append((newd,newr,newc,counting+1))
                check[newd][newr][newc] = 1
    while tempdq : 
        td,tr,tc = tempdq.popleft()
        tomato[td][tr][tc] = 1
    day=counting
    #print("day : ",day, tomato)

if tocount == 0 :
    print(day)
else : 
    print(-1)



