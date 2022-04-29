n = int(input())
nums = list(map(int, input().split()))
ans = 0
for i in nums:
    if (i != 1):
        tem = True
        for j in range(2,i):
            if (i % j == 0): #나누어 떨어진다.
                tem = False
                break
        if (tem):
            ans += 1
print(ans)
