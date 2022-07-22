n = int(input())

poster = [-1] * 100000001

for i in range(n):
    l, r = map(int, input().split())
    poster[l:r] = [i] * (r-l)

new_poster = []
for i in range(100000001):
    if poster[i] != -1:
        new_poster.append(poster[i])

print(len(set(new_poster)))
