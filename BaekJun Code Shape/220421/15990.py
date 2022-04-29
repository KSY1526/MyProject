import sys
n = int(input())

x = [4]
for _ in range(n):
    x.append(int(sys.stdin.readline()))

maxs = max(x) + 1
a1 = [0] * maxs
a2 = [0] * maxs
a3 = [0] * maxs
#a1 = [0, 1, 0, 1]
#a2 = [0, 0, 1, 1]
#a3 = [0, 0, 0, 1]
a1[1] = a2[2] = a1[3] = a2[3] = a3[3] = 1

for i in range(4, maxs):
    a1[i] = (a2[i-1]%1000000009 + a3[i-1]%1000000009)
    a2[i] = (a1[i-2]%1000000009 + a3[i-2]%1000000009)
    a3[i] = (a1[i-3]%1000000009 + a2[i-3]%1000000009)

for i in x[1:]:
    tem = a1[i] + a2[i] + a3[i]
    print(tem % 1000000009)

