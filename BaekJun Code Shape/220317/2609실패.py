def funs(x):
    lst = []
    while (x > 3):
        i = 2
        tem = x ** (1/2)
        while (i <= tem):
            if (x % i == 0):
                x = x // i
                lst.append(i)
                break
            i += 1
    if (x != 1):
        lst.append(x)
    return lst

a, b = map(int, input().split())

lsta = funs(a)
lstb = funs(b)

lst = []

for i in lsta:
    if i in lstb:
        lst.append(i)
        lstb.remove(i)

ans = 1
for i in lst:
    ans *= i

print(ans, round(a*b/ans))
# 시간초과, 유클리드 호제법으로 풀
    
