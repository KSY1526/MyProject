n = int(input())
ans = 0
for _ in range(n):
    words = input()
    tem = words[0]
    counts = len(set(words))
    for i in words[1:]:
        if (i != tem):
            tem = i
            counts = counts - 1
    if counts == 1:
        ans += 1
print(ans)
