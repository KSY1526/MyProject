t = int(input())

for _ in range(t):
    m, n, x, y = map(int, input().split())

    tem = x
    if n == y:
        y = 0
    while(True):
        if (tem % n == y):
            print(tem)
            break
        if (tem > n * m):
            print(-1)
            break
        tem += m
    
    
