t = int(input())

x = [1] * (11+1)
x[2] = 2

for i in range(3, 12):
    x[i] = x[i-1] + x[i-2] + x[i-3]

for _ in range(t):
    print(x[int(input())])
    
    
    


