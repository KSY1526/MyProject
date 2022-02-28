import math
a, b, v = map(int, input().split())
mount = a-b
print(math.ceil((v-a)/mount) + 1)
