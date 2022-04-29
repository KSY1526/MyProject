n = int(input())
# 미리 맵을 0으로 채운 것을 만듬
maps = [[0 for i in range(n)] for i in range(n)]

def countstar(n):
    if n == 3:
        maps[0][:3] = maps[2][:3] = [1] * 3
        maps[1][:3] = [1,0,1]
        return 
    a = n // 3
    countstar(a)
    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1:
                continue
            for k in range(a):
                maps[a*i + k][a*j:a*(j+1)] = maps[k][:a]
countstar(n)

for i in maps:
    for j in i:
        if j:
            print('*', end = '')
        else:
            print(' ', end = '')
    print()
