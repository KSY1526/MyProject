import sys
n = int(input())
a = []

def pushs(a, x):
    a.append(x)
def sizes(a):
    return len(a)
def emptys(a):
    return sizes(a) == 0
def pops(a):
    if emptys(a):
        return -1
    else:
        return a.pop()
def tops(a):
    if emptys(a):
        return -1
    else:
        return a[sizes(a)-1]

for i in range(n):
    words = sys.stdin.readline().split()
    order = words[0]
    if order == 'push':
        pushs(a, int(words[1]))
    elif order == 'pop':
        print(pops(a))
    elif order == 'size':
        print(sizes(a))
    elif order == 'empty':
        print(int(emptys(a)))
    else:
        print(tops(a))







        
