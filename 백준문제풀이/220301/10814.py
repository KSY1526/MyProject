n = int(input())
x = []
for i in range(n):
    age, names = input().split()
    x.append([int(age), names, i])

x.sort(key = lambda x : (x[0],x[2]))
for i in range(n):
    print(x[i][0], x[i][1])
             
