n = int(input())
def wordreverse(words):
    list(words).reverse()
for _ in range(n):
    words = list(input().split())
    for word in words:
        print(word[::-1], end =' ')
        # 파이썬 내 문자열 뒤집기는 정말 간단합니다.
    
