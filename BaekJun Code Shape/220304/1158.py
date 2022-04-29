n, k = map(int, input().split())
nums = list(range(1,n+1))
ans = []
popNum = 0

while n > 0:
    popNum = (popNum + (k-1)) % n
    ans.append(str(nums.pop(popNum)))
    n = n - 1
print('<', ', '.join(ans), '>', sep = '')
