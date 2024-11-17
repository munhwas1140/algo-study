import sys
input = sys.stdin.readline
t = int(input().strip())

for _ in range(t):
    left = []
    right = []
    cmd = input().strip()
    
    for i in cmd:
        if i == '<':
            if left:
                right.append(left.pop())
        elif i == '>':
            if right:
                left.append(right.pop())
        elif i == '-':
            if left:
                left.pop()
        else:
            left.append(i)
    left.extend(reversed(right))
    print(''.join(left))