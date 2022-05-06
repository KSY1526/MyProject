n, k = map(int, input().split())

a = [ [0] * (n+1) for i in range(k) ]
a[0] = [1] * (n+1)

for i in range(1, k):
    a[i][0] = 1
    for j in range(1, n+1):
        a[i][j] = a[i][j-1] + a[i-1][j]

print(a[k-1][n] % 1000000000)
