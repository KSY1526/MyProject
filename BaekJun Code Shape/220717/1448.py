import sys
# 오버라이딩, 오버로딩x 함수 재정의
input = sys.stdin.readline

n = int(input())

x = []
for _ in range(n):
    x.append(int(input()))

x.sort(reverse = True)
swich = True

for i in range(n-2):
    if x[i] < x[i+1] + x[i+2]:
        swich = False
        print(x[i] + x[i+1] + x[i+2])
        break

if swich:
    print(-1)
