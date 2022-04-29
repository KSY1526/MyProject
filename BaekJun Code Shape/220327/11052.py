n = int(input())

p = [0] + list(map(int, input().split()))
x = p[:]

for i in range(1,n+1):
    tem = i // 2 + i % 2
    for j in range(i, tem-1, -1):
        if (x[i] < x[i-j] + x[j]): # 16194는 중간 부등호만 바꿈
            x[i] = x[i-j] + x[j]

print(x[n])
