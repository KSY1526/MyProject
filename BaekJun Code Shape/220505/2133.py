n = int(input())

a = [0] * 31
a[0] = 1

for i in range(2, n+1, 2):
    a[i] = a[i-2] * 3

    for j in range(0, i-2, 2):
        a[i] += a[j] * 2

print(a[n])
