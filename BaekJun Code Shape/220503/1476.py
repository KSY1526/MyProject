e, s, m = map(int, input().split())

n = e
if s == 28:
    s = 0
if m == 19:
    m = 0
while(True):
    if n % 28 == s:
        if n % 19 == m:
            print(n)
            break
    n = n + 15
