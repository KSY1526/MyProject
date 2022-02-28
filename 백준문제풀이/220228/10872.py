def fator(x):
    if x == 1:
        return 1
    return x * fator(x - 1)

n = int(input())
if n == 0: # 0일때 고려 잘해줘야 합니다.
    print(1)
else:
    print(fator(n))
