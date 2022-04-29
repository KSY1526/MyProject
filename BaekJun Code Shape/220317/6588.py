check = [False, False] + [True] * 1000000
    
for i in range(2, 1001):
    if check[i] == True:
        for j in range(i + i, 1000001, i):
            check[j] = False

while (True):
    n = int(input())
    if n == 0:
        break
    swichs = True
    for i in range(3, n//2 + 3, 2):
        if (check[i] and check[n-i]):
            swichs = False
            print(n, '=', i, '+', (n-i))
            break
    if swichs:
        print("Goldbach's conjecture is wrong.")
    
