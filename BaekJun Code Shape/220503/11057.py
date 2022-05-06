n = int(input())

a = [ [0] * 10 for _ in range(n+2) ]

a[0] = [1] * 10

for i in range(1, n+2):
    for j in range(10):
        for k in range(9, j-1, -1):
            a[i][j] = (a[i][j] + a[i-1][k]) % 10007

print(a[n][0] % 10007)
