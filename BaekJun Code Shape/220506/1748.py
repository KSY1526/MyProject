n = int(input())
tem = n
i = 9
count = 0
while (tem > 0):
    tem = tem - i
    i = i * 10
    count = count + 1
i = i // 10
tem = tem + i
ans = tem * count

while(count > 0):
    count = count - 1
    i = i // 10
    ans += i * count


print(ans)
