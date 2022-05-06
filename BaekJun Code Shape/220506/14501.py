n = int(input())

a = [[0, 0]] * (n+1)

for i in range(1, n+1):
    a[i] = list(map(int, input().split()))

global ans
ans = 0
cost = []

def dfs(start):
    global ans
    if start > n:
        if start == n+1:
            sums = sum(cost)
        else:
            sums = sum(cost[:-1])
        if sums > ans:
            ans = sums

    for i in range(start, n+1):
        cost.append(a[i][1])
        dfs(i + a[i][0])
        cost.pop()

dfs(1)
print(ans)
        
