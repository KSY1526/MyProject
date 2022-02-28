n, m = map(int,input().split())
ans = []
if (n <= 2):
    ans.append(2)
    n += 1
for i in range(n, m+1):
    tem = True
    for j in range(2,int(i ** (1/2)+1)+1): # 시간단축
        if (i % j == 0): #나누어 떨어진다.
            tem = False
            break
    if tem == True:
        ans.append(i)    

for k in ans:
    print(k)
    
