while True:
    try:
        inputs = input()
        ans = [0] * 4
        for i in inputs:
            tem = ord(i)
            if tem <= 122 and tem >= 97:
                ans[0] += 1
            elif tem <= 90 and tem >= 65:
                ans[1] += 1
            elif tem <= 57 and tem >= 48:
                ans[2] += 1
            elif tem == 32:
                ans[3] += 1
        print(*ans)
    except EOFError:
        break
