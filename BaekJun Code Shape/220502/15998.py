t = int(input())
n = []
for _ in range(t):
    n.append(int(input()))
maxn = max(n)

a = [0] * (maxn + 1)
a[0] = 1
a[1] = a[0]
a[2] = a[1] + a[0]

for i in range(3, maxn + 1):
    a[i] = (a[i-1] + a[i-2] + a[i-3]) % 1000000009

for i in n:
    print(a[i] % 1000000009)
