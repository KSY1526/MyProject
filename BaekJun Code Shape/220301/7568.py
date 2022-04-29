n = int(input())
xx = []
yy = []
for _ in range(n):
    x, y = map(int, input().split())
    xx.append(x)
    yy.append(y)

for i in range(n):
    ans = 1
    for j in range(n):
        if (i == j):
            continue
        if (xx[i] < xx[j]):
            if (yy[i] < yy[j]):
                ans += 1
    print(ans, end = ' ')
            
