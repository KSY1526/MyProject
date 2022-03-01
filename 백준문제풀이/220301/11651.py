N=int(input())
arr=[]
for i in range(N):
    a,b = map(int,input().split())
    arr.append((b,a))
arr.sort()
for i in range(N):
    print(arr[i][1],arr[i][0])

# 다른 옵션 만질거 없이 입력 반대로 받고 출력 반대로 해주면 됩니
