n = int(input())
x = list(map(int, input().split()))
indexx = sorted(list(set(x)))
dicts = {indexx[i]: i for i in range(len(indexx))}

for i in x:
    print(dicts[i], end = ' ')
