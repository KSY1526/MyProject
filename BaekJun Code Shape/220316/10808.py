alphas = input()

counts = [0] * 26

for i in alphas:
    counts[ord(i)-97] += 1
print(*counts)
