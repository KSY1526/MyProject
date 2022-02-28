n = int(input())
max5 = n // 5 

for i in range(max5, -1, -1):
    division3 = n - i * 5
    if (division3 % 3) == 0:
        print(i + int(division3/3))
        i = 1
        break
if (i == 0):
    print(-1)
    
