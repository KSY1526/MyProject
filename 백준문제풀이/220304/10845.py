import sys
num = int(input())
que = []

def sizes():
    return len(que)

def pushs(x):
    que.append(x)

def emptys():
    return len(que) == 0

def pops():
    if emptys():
        return -1
    else:
        return que.pop(0)

def fronts():
    if emptys():
        return -1
    else:
        return que[0]

def backs():
    if emptys():
        return -1
    else:
        return que[-1]

for i in range(num):
    tem = sys.stdin.readline().split()
    if (tem[0] == 'push'):
        pushs(tem[1])
    elif (tem[0] == 'pop'):
        print(pops())
    elif (tem[0] == 'size'):
        print(sizes())
    elif (tem[0] == 'empty'):
        print(int(emptys()))
    elif (tem[0] == 'front'):
        print(fronts())
    elif (tem[0] == 'back'):
        print(backs())
        
    
