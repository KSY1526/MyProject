a, b = map(int, input().split())
n = int(input())
x = [0] * n
for i in range(n):
    x[i] = int(input())

mins = abs(a - b)

for i in x:
    tem = (abs(i - b) + 1)
    
    if mins > tem:
        mins = tem

print(mins)
