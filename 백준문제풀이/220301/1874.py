n = int(input())
buffers = []
stack = []
ans = []
for i in range(n, 0, -1):
    stack.append(i)

for i in range(n):
    if (len(stack) == 0):
        while (len(buffers) != 0):
            x = int(input())
            if (buffers.pop() != x):
                ans = ['NO']
                break
            ans.append('-')            
            i += 1
            
        if ans == ['NO']:
            for j in range(i+1, n):
                x = int(input()) # 일단 다 뽑긴 해야함
        break
        
    x = int(input())
    
    tops = stack[len(stack)-1]
    if (tops <= x):
        for j in range(x- tops+1):
            buffers.append(stack.pop())
            ans.append('+')
        buffers.pop()
        ans.append('-')
    elif (buffers.pop() == x):
        ans.append('-')
    else:
        ans = ['NO']
        break

for i in ans:
    print(i)
        
    
