ans = []

num = int(input())
for i in range(num):
    h,w,n = map(int, input().split())
    ww = n // h + 1
    hh = n % h
    if hh == 0:
        hh = h
        ww = ww - 1
    ans.append(hh * 100 + ww)

for i in ans:
    print(i)
