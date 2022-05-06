n = int(input())

x = list(map(int, input().split()))

maxs = tem = 0
for i in x:
    tem = tem + i
    if tem < 0:
        tem = 0
    elif maxs < tem:
        maxs = tem
if maxs == 0:
    maxs = max(x)
print(maxs)
