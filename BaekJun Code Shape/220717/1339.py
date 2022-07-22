n = int(input())

from string import ascii_uppercase

alpha_list = list(ascii_uppercase)
cnt = [0] * 26

for i in range(n):
    tem = input()
    values = 1
    for j in tem[::-1]:
        for k in range(26):
            if alpha_list[k] == j:
                cnt[k] += values
                values = values * 10
                break

cnt.sort(reverse = True)
values = 9
result = 0
for i in cnt:
    if i == 0:
        print(result)
        break
    result += i * values
    values = values - 1






