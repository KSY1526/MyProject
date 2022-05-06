import sys
from collections import deque
m, n = map(int, input().split())

graph = []

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))

queue = deque()
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            queue.append((i,j))

dx = [-1,1,0,0]
dy = [0,0,-1,1]

while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue

        if graph[nx][ny] == -1:
            continue
        if graph[nx][ny] == 0:
            graph[nx][ny] = graph[x][y] + 1
            queue.append((nx,ny))


ans = 0
swich = True
for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            swich = False
            print(-1)
            break
    if swich == False:
        break
    ans = max(ans, max(graph[i]))

if swich == True:
    print(ans - 1)
       
