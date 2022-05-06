n, m = map(int, input().split())

x = list(map(int, input().split()))
x.sort()
s = []

def dfs():
    if len(s) == m:
        for i in s[:-1]:
            print(x[i], end = ' ')
        print(x[s[-1]])
        return
    tem = -1
    for i in range(0, n):
        if x[i] == tem or i in s:
            continue
        s.append(i)
        dfs()
        tem = x[s.pop()]

dfs()
