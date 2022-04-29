check = [False, False] + [True] * 1000000
    
for i in range(2, 1001):
    if check[i] == True:
        for j in range(i + i, 1000001, i):
            check[j] = False

n = int(input())

for _ in range(n):
    x = int(input())
    count = 0
    for i in range(2, x//2 + 1):
        if (check[i] and check[x-i]):
            count += 1
    print(count)
