from collections import deque

n, k = map(int, input().split())

def bfs():
    q = deque()
    q.append([n])
    while (q):
        lst = q.popleft()
        tem = lst[-1]
        if tem > 100000 or tem < 0:
            continue
        if tem == k:
            break
        q.append(lst + [tem + 1])
        q.append(lst + [tem - 1])
        q.append(lst + [tem * 2])

    print(len(lst))
    print(*lst)
    
bfs()
        
