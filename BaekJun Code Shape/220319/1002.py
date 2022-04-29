n = int(input())

for _ in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (1/2)

    x = sorted([r1, r2, d])
    
    if d == 0:
        if r1 == r2:
            print(-1)
        else:
            print(0)

    elif x[2] > (x[0] + x[1]):
        print(0)

    elif x[2] == (x[0] + x[1]):
        print(1)

    else:
        print(2)




        
