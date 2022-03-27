a, b = map(int, input().split())
twos, fives = 0, 0

def fun(num):
    tem2, tem5 = 0, 0
    while (num % 2 == 0):
        tem2 += 1
        num = num // 2     
    while (num % 5 == 0):
        tem5 += 1
        num = num // 5
    return tem2, tem5

if (a-b) < b:
    b = a - b


for _ in range(b):
    t2, t5 = fun(a)
    twos += t2
    fives += t5
    a -= 1

    t2, t5 = fun(b)
    twos -= t2
    fives -= t5
    b -= 1

print(min(twos, fives))   
