n = int(input())

a = [[0,0] for _ in range(n+1)]

a[1] = [1,1]

for i in range(2, n+1):
    a[i][0] = a[i-1][0] + a[i-1][1]
    a[i][1] = a[i-1][0]

print(a[n][1])
