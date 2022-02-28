A, B, C = map(int, input().split())

if (C > B):
    i = int( A / (C - B)) + 1
else:
    i = -1
print(i)
