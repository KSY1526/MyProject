n, m = map(int,input().split())
x = list(map(int, input().split()))
maxs = 10
for i in range(n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            sums = x[i] + x[j] + x[k]
            if (sums <= m):
                if (sums > maxs):
                    maxs = sums
print(maxs)
