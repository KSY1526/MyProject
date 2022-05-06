n = int(input())
a = [ int(x) for x in input().split() ]

s = []

global ans
ans = 0
def dfs():
    global ans
    if len(s) == n:
        sums = 0
        for i in range(1,n):
            sums += abs(a[s[i-1] - 1] - a[s[i] - 1])

        if ans < sums:
            ans = sums
        return

    for i in range(1, n+1):
        if i in s:
            continue
        s.append(i)
        dfs()
        s.pop()

dfs()
print(ans)



