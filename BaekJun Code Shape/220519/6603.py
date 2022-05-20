while(True):
    s = list(map(int, input().split()))

    if s[0] == 0:
        break
    x = []
    def dfs(start):
        if len(x) == 6:
            for i in x[:-1]:
                print(s[i], end = ' ')
            print(s[x[-1]])
            return

        for i in range(start, s[0] + 1):
            x.append(i)
            dfs(i+1)
            x.pop()

    
    dfs(1)
    print()
            
