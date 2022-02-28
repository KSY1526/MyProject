a, b = map(list, input().split())
if (a[2] > b[2]):
    a.reverse()
    for i in a:
        print(i, end = '')
elif (a[2] < b[2]):
    b.reverse()
    for i in b:
        print(i, end = '')
else:
    if (a[1] > b[1]):
        a.reverse()
        for i in a:
            print(i, end = '')
    elif (a[1] < b[1]):
        b.reverse()
        for i in b:
            print(i, end = '')
    else:
        if (a[0] > b[0]):
            a.reverse()
            for i in a:
                print(i, end = '')
        else:
            b.reverse()
            for i in b:
                print(i, end = '')


    
