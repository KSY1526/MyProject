x = int(input())
i = 0
while(x > 1):
    if x % 3 == 0:
        x = x // 3
    elif x % 2 == 0:
        x = x // 2
    else:
        x = x - 1
    i = i + 1
    print(x)
print(i)
