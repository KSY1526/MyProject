import math

n, s = map(int, input().split())
x = list(map(int, input().split()))

for i in range(n):
    x[i] = s - x[i]
    if x[i] < 0:
        x[i] = x[i] * -1

if n == 1:
    d = x[i]
else:
    d = math.gcd(x[0], x[1])

    for i in range(2, n):
        d = math.gcd(d, x[i])
print(d)

