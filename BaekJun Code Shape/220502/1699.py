n = int(input())

a = [x for x in range (n+1)]

for i in range(2, n+1):
    for j in range(1, i):
        if i < j * j:
            break
        elif a[i] > a[i - j * j] + 1:
            a[i] = a[i - j * j] + 1

print(a[n])
