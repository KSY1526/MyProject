n = int(input())
for _ in range(n):
    buffers = []
    inputs = input()
    for i in inputs:
        if (i == '('):
            buffers.append(1)
        else:
            if len(buffers) == 0:
                buffers = [1]
                break
            else:
                buffers.pop()
    if len(buffers) == 0:
        print('YES')
    else:
        print('NO')
    
