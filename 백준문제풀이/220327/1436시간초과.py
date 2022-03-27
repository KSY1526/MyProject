x = int(input())

def funs(n):
    if n == 1:
        return 0
    elif n % 3 == 0:
        return 1 + min(funs(n//3), funs(n-1))
    elif n % 2 == 0:
        return 1 + min(funs(n//2), funs(n-1))
    else:
        return 1 + funs(n-1)

print(funs(x))

    
