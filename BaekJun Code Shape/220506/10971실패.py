import sys


def dfs(start, next, value, visited):
    global min_value

    if len(visited) == N:
        if travel[next][start] != 0:
            min_value = min(min_value, value + travel[next][start])
        return

    for i in range(N):
        if travel[next][i] != 0 and i not in visited:
            visited.append(i)
            dfs(start, i, value + travel[next][i], visited)
            visited.pop()


N = int(input())
travel = [list(map(int, input().split())) for _ in range(N)]

min_value = sys.maxsize

# 각 번호에서 시작
for i in range(N):
    dfs(i, i, 0, [i])

print(min_value)
