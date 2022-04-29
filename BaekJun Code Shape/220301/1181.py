import sys
n = int(sys.stdin.readline())
x = []
for _ in range(n):
    x.append(input())
x = list(set(x))
x.sort()
x.sort(key = len) # 정말 사기네요. 파이썬 내장함수.
for i in x:
    print(i)
