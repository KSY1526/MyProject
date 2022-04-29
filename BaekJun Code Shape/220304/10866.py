from collections import deque
import sys

n = int(input())
ques = deque()

def isempty():
    return len(ques) == 0


for _ in range(n):
    tem = sys.stdin.readline().split()
    if tem[0] == 'push_front':
        ques.appendleft(tem[1])
    elif tem[0] == 'push_back':
        ques.append(tem[1])
    elif tem[0] == 'pop_front':
        if isempty():
            print(-1)
        else:
            print(ques.popleft())
    elif tem[0] == 'pop_back':
        if isempty():
            print(-1)
        else:
            print(ques.pop())
    elif tem[0] == 'size':
        print(len(ques))
    elif tem[0] == 'empty':
        print(int(isempty()))
    elif tem[0] == 'front':
        if isempty():
            print(-1)
        else:
            print(ques[0])
    elif tem[0] == 'back':
        if isempty():
            print(-1)
        else:
            print(ques[-1])



        
