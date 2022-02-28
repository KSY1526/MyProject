n = int(input())
ans = []
def distributions(x):
    for i in range(2,x):
        tem = True
        if (x % i == 0):
            tem = False
            break
    return tem #소수가 아닐때 True

while (n % 2 == 0):
    n = n // 2
    ans.append(2)
while (n % 3 == 0):
    n = n // 3
    ans.append(3)
while (n % 5 == 0):
    n = n // 5
    ans.append(5)
while (n % 7 == 0):
    n = n // 7
    ans.append(7)
for j in range(11, int(n ** (1/2) + 1)): # 시간 단축
    if (distributions(j)):
        while(n % j == 0):
            n = n // j
            ans.append(j)
if n != 1:
    ans.append(n)
for k in ans:
    print(k)
    
    
