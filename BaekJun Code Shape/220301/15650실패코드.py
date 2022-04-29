n, m = map(int, input().split())
if ( n//2 >= m):
    if (m == 1):
        for i in range(1, n+1):
            print(i)
    elif (m == 2):
        for i in range(1, n):
            for j in range(i+1, n+1):
                print(i, j)
    elif (m == 3):
        for i in range(1, n-1):
            for j in range(i+1, n):
                for k in range(j+1, n+1):
                    print(i, j, k)
    else:
        for i in range(1, 6):
            for j in range(i+1, 7):
                for k in range(j+1, 8):
                    for p in range(k+1, 9):
                        print(i, j, k, p)
else:
    revm = n - m
    if (revm == 0):
        for i in range(1, n+1, 1):
            print(i, end = ' ')
    elif (revm == 1):
        for i in range(n, 0, -1):
            for j in range(1, n+1, 1):
                if (i == j):
                    continue
                print(j, end =' ')
            print()
    elif(revm == 2):
        for i in range(n, 1, -1):
            for j in range(i-1, 0, -1):
                for k in range(1, n+1, 1):
                    if (i == k) or (j == k):
                        continue
                    print(k, end =' ')
                print()
    else:
        for i in range(n, 2, -1):
            for j in range(i-1, 1, -1):
                for k in range(j-1, 0, -1):
                    for p in range(1, n+1, 1):
                        if (i == p) or (j == p) or (k == p):
                            continue
                        print(p, end =' ')
                    print()






                
                    
