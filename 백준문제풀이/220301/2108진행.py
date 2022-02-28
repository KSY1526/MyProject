n = int(input())
x = []
for i in range(n):
    x.append(int(input()))
x.sort()
print(round(sum(x)/n))
print(x[n//2])
count = 1
manycount = 1
tem = x[0]
manys = x[1]
swichs = True
for i in x[1:]:
    if (tem == i):
        count += 1
    else:
        count = 1
        tem = i
    if (count > manycount) and (manys != i):
        swichs = True
        manys = i

        
print(x[n-1] - x[0])
