def directer(x):
    if (x % 2 == 0):
        return False
    for i in range(3,int(x **(1/2)) + 1,2):
        if (x % i) == 0:
            return False
    return True

while (1):
    n = int(input())
    if n == 0:
        break
    ans = 0
    if n == 1:
        ans += 1
        
    for i in range(n+1, 2*n + 1):
        if (directer(i)):
            ans += 1
    print(ans)

# 파이썬 언어의 한계로 시간초과...
# 에라토스테네스의 체 개념을 익히면 됨. 중요하진 않아서 패스
