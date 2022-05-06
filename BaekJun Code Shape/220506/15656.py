n, m = map(int, input().split())

x = list(map(int, input().split()))
x.sort()
s = []

def dfs(start):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(0, n):
        s.append(x[i])
        dfs(i)
        s.pop()

dfs(0)
