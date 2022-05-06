import sys
n = int(input())

a = [ int(x) for x in sys.stdin.readline().split()]

k = -1

for i in range(n-1):
    if a[i] < a[i+1]:
        k = i

if k == -1: # 내림차순일때
    print(-1)

else:
    for j in range(k+1, n):
        if a[k] < a[j]:
        # 이 조건을 만족하는 값 중 가장 뒤에값
            m = j

    a[k], a[m] = a[m], a[k]
    ans = a[:k+1] + sorted(a[k+1:])
    print(*ans)

# https://hooongs.tistory.com/201

    









