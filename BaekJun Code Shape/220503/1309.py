n = int(input())

a = [ [0] * 2 for _ in range(n+2) ]

a[2] = [ 2, 3 ]

for i in range(3, n+2):
    a[i][0] = (a[i-1][0] + a[i-1][1]) % 9901
    a[i][1] = (a[i-1][0] * 2 + a[i-1][1]) % 9901

print(a[n+1][1] % 9901)
    
