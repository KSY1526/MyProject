from itertools import combinations

n, m = map(int, input().split())

city = []
for _ in range(n):
    city.append(list(map(int, input().split())))

house = []
chicken = []

for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            house.append([i, j])
        elif city[i][j] == 2:
            chicken.append([i, j])

mins = 100000

# 전체 치킨집 중 m개를 뽑는 모든 케이스를 리스트화함
# c에는 한 종류의 m개 치킨집 리스트가 존재

for chi in combinations(chicken, m):
    minsums = 0
    for h in house:        
        minh = 10000
        for c in chi:
            tem = abs(c[1] - h[1]) + abs(c[0] - h[0])
            if minh > tem:
                minh = tem
        minsums += minh

    if mins > minsums:
        mins = minsums

print(mins)
    
