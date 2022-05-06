x = [0] * 9
for i in range(9):
    x[i] = int(input())

def fun():
    for a in range(0, 3):
        for b in range(a+1, 4):
            for c in range(b+1, 5):
                for d in range(c+1, 6):
                    for e in range(d+1, 7):
                        for f in range(e+1, 8):
                            for g in range(f+1, 9):
                                tem = x[a]+x[b]+x[c]+x[d]+x[e]+x[f]+x[g]
                                if tem == 100:
                                    p = [x[a],x[b],x[c],x[d],x[e],x[f],x[g]]
                                    p.sort()
                                    for i in p:
                                        print(i)
                                    return

fun()

