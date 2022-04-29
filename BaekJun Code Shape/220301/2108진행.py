import sys
n = int(sys.stdin.readline()) # 시간초과 방지
x = []
for i in range(n):
    x.append(int(sys.stdin.readline()))
x.sort()
print(round(sum(x)/n))
print(x[n//2])
count = 1
manycount = 1
tem = x[0]
if n == 0:
    startidx = 0
else:
    startidx = 1
manys = x[startidx]
swichs = True
for i in x[startidx:]:
    if (tem == i):
        count += 1
        if (count == manycount) and (swichs):
            # 같은 빈도가 2번째로 카운트 된 경우
            manys = i
            swichs = False
    else:
        if (count > manycount):
            swichs = True
            manys = tem
            manycount = count

        count = 1
        tem = i
print(manys)
print(x[n-1] - x[0])
