n = int(input())

a = [ [0] * n for _ in range(n) ]

for i in range(n):
    a[i] = list(map(int, input().split()))

visited = [False] * n
val = 100000000
cost = []
def dfs(start):
    global val

    if sum(visited) == n-1:
        if a[start][0] == 0:
            return
        cost.append(a[start][0])
        if val > sum(cost):
            val = sum(cost)
        cost.pop()
        return

    for i in range(1, n):
        if (visited[i] == True) or (a[start][i] == 0):
            continue
        cost.append(a[start][i])
        
        if sum(cost) > val:
            cost.pop()
            continue
        visited[i] = True
        
        dfs(i)

        cost.pop()
        visited[i] = False
        
dfs(0)
print(val)

        






        
