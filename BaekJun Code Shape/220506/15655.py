n, m = map(int, input().split())

x = list(map(int, input().split()))
x.sort()
s = []

def dfs(start):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(start, n):
        s.append(x[i])
        dfs(i+1)
        s.pop()

dfs(0)
