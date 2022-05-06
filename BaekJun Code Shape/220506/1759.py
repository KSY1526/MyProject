l, c = map(int, input().split())

x = list(input().split())
x.sort()

s = []
def dfs(start):
    if len(s) == l:
        tem = ''
        for i in s:
            tem += x[i]
            
        count = 0
        
        for i in tem:
            if i in 'aeiou':
                count += 1
        if count > 0 and count <= l - 2:
            print(tem)

        return

        
    for i in range(start, c):
        if i in s:
            continue
        s.append(i)
        dfs(i+1)
        s.pop()

dfs(0)
