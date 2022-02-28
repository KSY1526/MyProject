num = input()
lens = len(num)
num = int(num)
distri = True
for i in range(num- lens*9, num - lens + 1):
    sums = 0
    if i < 0:
        continue
    for j in str(i):
        sums += int(j)
    if (num == i + sums):
        print(i)
        distri = False
        break
if distri:
    print(0)
    
