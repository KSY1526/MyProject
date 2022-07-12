n = int(input())
x = [[0, 0, 0] for _ in range(n)] 

for i in range(n):
    x[i] = list(map(int, input().split()))

x.sort(key = lambda a : a[1])

room = [-1]

for i in x:
    if room[0] <= i[1]:
        room[0] = i[2]
        room.sort()
        # 시간복잡도 n*logn sort를 n번 반복해 시간초과가 나옴
    else:
        if room[0] > i[2]:
            tem = room[0]
            room[0] = i[2]
            room.append(tem)
        else:
            room.append(i[2])

print(len(room))
