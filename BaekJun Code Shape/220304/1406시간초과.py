import sys
words = input()
moves = len(words) 
lens = moves + 1

num = int(input())

def minuses(x):
    if x > 0:
        x += -1
    return x

for i in range(num):
    tem = sys.stdin.readline().split()
    if tem[0] == 'L':
        moves = minuses(moves)
    elif tem[0] == 'D':
        if moves == lens:
            continue
        moves += 1
    elif tem[0] == 'B':
        if moves == 0:
            continue        
        words = words[:(moves-1)] + words[moves:]
        moves = minuses(moves)
        lens = minuses(lens)
    else:
        words = words[:(moves)] + tem[1] + words[(moves):]
        moves += 1
        lens += 1

print(words)
    
