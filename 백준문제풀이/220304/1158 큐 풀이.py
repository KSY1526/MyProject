from collections import deque

N, K = map(int, input().split())

R = []
queue = deque()
for i in range(1,N+1):
    queue.append(i)
    
while queue:
    for i in range(K-1):
        queue.append(queue.popleft())
    R.append(queue.popleft())
    
print('<', end = '')
print(*R, sep = ', ', end = '')
print('>')
