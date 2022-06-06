n = int(input())

bu = list(input().split())
s = []

def check(x):
    realbu = []
    swich = True
    
    for i in range(n-1):
        if x[i] > x[i+1]:
            realbu += ['>']
        else:
            realbu += ['<']
            
    for i in range(n):
        if realbu[i] != bu[i]:
            swich = False
            break
        
    return swich

swichs = True

def dfs_min():
    global swichs
    if len(s) == n:
        if check(s):
            swichs = False
            print(*s)
        return

    for i in range(10):
        if i in s:
            continue
        s.append(i)
        dfs_min()
        if not swichs:
            return
        s.pop()

dfs_min()

    








