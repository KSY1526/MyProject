n = int(input())

s = []

def dfs():
    if len(s) == n:
        print(*s)
        return

    for i in range(1, n+1):
        if i in s:
            continue
        s.append(i)
        dfs()
        s.pop()

dfs()
