n, m = map(int, input().split())
people = []
numbers = []

# 아는사람 집합으로 넣음
tem = list(map(int, input().split()))
knows = set(tem[1:])
partys = [1] * m

# 파티 입력
for _ in range(m):
    tem = list(map(int, input().split()))
    numbers.append(tem[0])
    people.append(tem[1:])

swichs = True # 만족 될때까지 계속 돌림
while (swichs) :
    swichs = False
    for i in range(m):
        if (partys[i] == 0):
            continue
        for j in people[i]:
            if (j in knows):
                partys[i] = 0
                knows.update(people[i])
                swichs = True
                break
        if (swichs == True):
            break

print(sum(partys))
        
