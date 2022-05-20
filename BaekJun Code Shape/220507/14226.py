from collections import deque

n = int(input())

# 화면 이모티콘, 클립보드 이모티콘 배열
dist = [ [-1] * (n+1) for _ in range(n+1) ]

q = deque()
q.append((1,0))
dist[1][0] = 0
while q:
    s, c = q.popleft()
    # 1. 화면 클립보드에 복사
    if dist[s][s] == -1:
        dist[s][s] = dist[s][c] + 1
        q.append((s,s))
    # 2. 클립보드를 화면에 복사
    if s + c <= n and dist[s+c][c] == -1:
        dist[s+c][c] = dist[s][c] + 1
        q.append((s+c,c))
    # 3. 화면 내용 하나 빼기
    if s - 1 >= 0 and dist[s-1][c] == -1:
        dist[s-1][c] = dist[s][c] + 1
        q.append((s-1,c))

answer = -1

for i in range(n+1):
    if dist[n][i] != -1:
        if answer == -1 or answer > dist[n][i]:
            answer = dist[n][i]
print(answer)






    
    
