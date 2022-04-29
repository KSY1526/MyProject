n = int(input())
lst = list(map(int, input().split()))

stack=[]
result=[-1]*n
for i in range(n):
    while stack:
        if lst[i]>lst[stack[-1]]:
            result[stack.pop()]=lst[i]            
        else:
            break
    stack.append(i)

# 리스트 출력하는 법
print(*result)
