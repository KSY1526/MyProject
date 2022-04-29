n = int(input())
lst = list(map(int, input().split()))
swichs = False

counts = 0
for i in lst[:-1]:
    counts += 1
    for j in lst[counts:]:
        if j > i:
            print(j, end = ' ')
            swichs = True
            break
    if swichs == False:
        print(-1, end =' ')

print(-1)
