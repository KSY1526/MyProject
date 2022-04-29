n = int(input())
x = []
for i in range(n):
    x.append(int(input()))
x.sort()

for i in range(n):
    print(x[i])
