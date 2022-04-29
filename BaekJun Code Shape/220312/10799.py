lst = list(input())
stack = []
points = 0
ans = 0
tag = True

for i in lst:
    if i == '(':
        tag = True
        stack.append(0)
    else:
        if tag:
            stack.pop()
            stack.append(1)
            tag = False
        else:
            pops = stack.pop()
            tem = pops
            while (pops):
                pops = stack.pop()
                tem += pops
            points += tem + 1
            stack.append(tem)
print(points)               
                
            
