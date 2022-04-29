n = int(input())

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

for _ in range(n):
    x = list(map(int, input().split()))
    ans = 0
    for i in range(1, x[0]):
        for j in range(i + 1, x[0] + 1):
            ans += gcd(x[i], x[j])
    print(ans)
    
