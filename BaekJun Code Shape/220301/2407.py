n, m = map(int, input().split())
ans = 1
if n / 2 > m:
    for i in range(n, n-m, -1):
        ans = ans * i
    for j in range(1, m+1):
        ans = ans // j
        # 이부분 나눠주고 int 씌우면 파이썬 오차때문에 틀리는게 생김
    print(ans)
else:
    m = n - m
    for i in range(n, n-m, -1):
        ans = ans * i
    for j in range(1, m+1):
        ans = ans // j
    print(ans)
