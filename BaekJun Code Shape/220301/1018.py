n, m = map(int, input().split())
x = []
for i in range(n):
    x.append(list(input()))
    
mincount = 32
for i in range(n-7):
    for j in range(m-7):
        count = 0
        for ii in range(i, i + 8):
            for jj in range(j, j + 8):                
                if ((ii + jj) % 2 == 0) and (x[ii][jj] == 'W'): # 짝수일때
                    count += 1
                elif ((ii + jj) % 2 == 1) and (x[ii][jj] == 'B'): # 홀수일때
                    count += 1
        if count > 32:
            count = 64 - count
        if mincount > count:
            mincount = count
print(mincount)

        
