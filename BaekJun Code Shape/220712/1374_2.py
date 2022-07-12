import heapq
# https://www.daleseo.com/python-heapq/
# 쉽게 생각하면 정렬이 필요하기 보다 최솟값 보장 중요.

n = int(input())
x = [[0, 0, 0] for _ in range(n)] 

for i in range(n):
    x[i] = list(map(int, input().split()))

x.sort(key = lambda a : a[1])

# 초기값 설정
room = [x[0][2]]

for i in x[1:]:
    if room[0] <= i[1]:
        heapq.heappop(room)
    # heapq.heappush는 시간복잡도 logn을 가짐
    heapq.heappush(room, i[2])
print(len(room))
