num = int(input())

for _ in range(num):
    k = int(input())
    n = int(input())
    human = list(range(n + 1))
    for i in range(k):
        for j in range(1,n+1):
            human[j] += human[j-1]
    print(human[n])
