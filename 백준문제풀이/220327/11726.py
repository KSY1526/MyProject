n = int(input())
x = [0] * (n+1)
x[1] = 1
if n >= 2:
    x[2] = 2 # 11727은 여기서 3
    for i in range(3,n+1):
        x[i] = x[i-1] + x[i-2] # 11727 x[i-2] * 2
print(x[n] % 10007)
