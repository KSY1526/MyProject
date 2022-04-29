import sys
n = int(sys.stdin.readline()) 
x, y = map(int, sys.stdin.readline().split())
xy = [(x,y)]

for k in range(1, n):
    x, y = map(int, sys.stdin.readline().split())
    maxs = True
    for i in range(k):
        if xy[i][0] == x:
            if xy[i][1] > y:
                xy.insert(i, (x,y))
                maxs = False
                break
            continue
        if xy[i][0] > x:
            xy.insert(i, (x,y))
            maxs = False
            break        
    if maxs:
        xy.append([x,y])

for i in range(n):
    print(xy[i][0], xy[i][1])

# 시간이 계속 초과됩니다.. 구현한거에 만족하고 파이썬 내장함수 짱짱! 
