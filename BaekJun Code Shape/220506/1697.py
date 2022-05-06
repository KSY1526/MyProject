from collections import deque
n, k = map(int, input().split())

def bfs():
    queue = deque()
    queue.append(n)

    while queue:
        x = queue.popleft()
        if x == k:
            print(dist[x])
            break

        for i in (x-1,x+1, x*2):
            if i >= 0 and i <= 100000 and not dist[i]:
                dist[i] = dist[x] + 1
                queue.append(i)

dist = [0] * 100001
bfs()
