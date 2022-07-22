n = int(input())
num = int(input())

x = list(map(int, input().split()))

ans = []
cut = []

for i in x:
    swich = True
    for j in range(len(ans)):
         if i == ans[j]:
             cut[j] += 1
             swich = False
             break
        
    # 현재 후보자가 아닌 사람을 추천한 경우
    if swich and (len(ans) == n):
        mins = min(cut)
        for j in range(n):
            # 첫번째로 만나는 최솟값이
            # 가장 오래된 후보 = 제거될 대상
            if (mins == cut[j]):
                del cut[j]
                del ans[j]
                # 가장 오래된 후보가 앞에 있는 이유는
                # 새로운 후보 등록을 뒤에서 넣기 때문(큐)
                #ans.append(i)
                #cut.append(1)
                break
    if swich:
        ans.append(i)
        cut.append(1)

# 리스트를 한번에 출력하는 방법
print(*sorted(ans))
        
    
        
             
