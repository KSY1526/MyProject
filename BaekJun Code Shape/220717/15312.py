lists = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]

me = input()
her = input()

num = []

n = len(me)
for i in range(n):
    num.append(lists[ord(me[i]) - 65])
    num.append(lists[ord(her[i]) - 65])

for i in range(n*2-1, 1, -1):
    tem = []
    for j in range(i):
        tem.append((num[j] + num[j+1]) % 10)
    num = tem[:]

print(str(num[0]) + str(num[1]))

        
