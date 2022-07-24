# 오후 10시 37분
import copy
import sys
from collections import deque

n = int(sys.stdin.readline())
map = [[0 for col in range(n)] for row in range(n)]

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

answer = 0


def BFS(map, x, y):
    v = [[False for col in range(n)] for row in range(n)]
    dq = deque()
    dq.append([x, y])
    v[x][y] = True
    result = 0
    count = 1
    while dq:
        i, j = dq.popleft()
        result = max(result, count)
        for k in range(0,4,2):
            newx, newy = i + dx[k], j + dy[k]
            if 0 <= newx < n and 0 <= newy < n and v[newx][newy] == False and map[x][y] == map[newx][newy]:
                count+=1
                dq.append((newx, newy))
                v[newx][newy] = True
    dq.append([x, y])
    result = max(result, count)
    count = 1
    while dq:
        i, j = dq.popleft()
        result = max(result, count)
        for k in range(1,4,2):
            newx, newy = i + dx[k], j + dy[k]
            if 0 <= newx < n and 0 <= newy < n and v[newx][newy] == False and map[x][y] == map[newx][newy]:
                count+=1
                dq.append((newx, newy))
                v[newx][newy] = True
    return result


def check_status(map, x, y):
    result = 0
    for i in range(4):
        tempmap = copy.deepcopy(map)
        newx = x + dx[i]
        newy = y + dy[i]
        if 0 <= newx < n and 0 <= newy < n and map[x][y] != map[newx][newy]:
            tempmap[x][y], tempmap[newx][newy] = tempmap[newx][newy], tempmap[x][y]
            result = max(result, BFS(tempmap, x, y))
    return result


for i in range(n):
    inputstr = input().split()
    for j in range(n):
        convert = inputstr[0][j:j + 1]
        map[i][j] = convert

for i in range(n):
    for j in range(n):
        answer = max(BFS(map, i, j), check_status(map, i, j), answer)

print(answer)
