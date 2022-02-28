n = int(input())
m = int(input())
ans = []
if (n == 1):
    n = 2
for i in range(n, m+1):
    tem = True
    for j in range(2,i):
        if (i % j == 0): #나누어 떨어진다.
            tem = False
            break
    if (tem):
        ans.append(i)
sums = sum(ans)
if (sums == 0):
    print(-1)
else:
    print(sums)
    print(min(ans))
