cal = input()
stack = []
for i in cal:
    if i == '(':
        stack.append('(')
        continue
    elif i == ')':
        while (True):
            tem = stack.pop()
            if tem == '(':
                break
            print(tem, end ='')            
        continue
    elif i in ['*', '/']:
        while stack and (stack[-1] in ['*', '/']):
            print(stack.pop(), end ='')
        stack.append(i)
        continue
    elif i in ['+', '-']:
        while stack and (stack[-1] != '('):
            print(stack.pop(), end ='')
        stack.append(i)
        continue
    else:
        print(i, end='')

while(stack):
    print(stack.pop(), end='')



    
