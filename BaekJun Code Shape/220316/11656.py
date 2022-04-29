inputs = input()
tem = []
for i in range(len(inputs)):
    tem.append(inputs[i:])
tem.sort()
for i in tem:
    print(i)
