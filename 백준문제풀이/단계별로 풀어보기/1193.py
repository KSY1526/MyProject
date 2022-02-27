x = int(input())
i = 1
sums = 1
while( sums < x):
    i = i + 1
    sums = sums + i
tem = sums - x

if i % 2 == 0:
    print((i - tem), '/' ,(1 + tem), sep = '')
else:
    print((1 + tem), '/' ,(i - tem), sep = '')

