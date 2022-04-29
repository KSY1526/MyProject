n = int(input())
counts = 0
for i in range(1, n+1):
    if i < 100:
        counts += 1
    else:
        num1 = i // 100
        num2 = (i % 100) // 10
        num3 = i % 10
        if (num2 * 2 == num1 + num3):
            counts += 1
print(counts)
            
        
