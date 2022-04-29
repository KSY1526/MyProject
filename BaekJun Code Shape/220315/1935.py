n = int(input())
cal = input()

num = [0] * n
for i in range(n):
    num[i] = int(input())

stack = []
signs = ['+', '-', '*', '/']

for i in cal:
    if i == '+':
        tem2 = stack.pop()
        tem1 = stack.pop()
        stack.append(tem1 + tem2)
    elif i == '-':
        tem2 = stack.pop()
        tem1 = stack.pop()
        stack.append(tem1 - tem2)
    elif i == '*':
        tem2 = stack.pop()
        tem1 = stack.pop()
        stack.append(tem1 * tem2)
    elif i == '/':
        tem2 = stack.pop()
        tem1 = stack.pop()
        stack.append(tem1 / tem2)

    else:
        stack.append(num[ord(i)-65])

print('{:.2f}'.format(stack[0]))
