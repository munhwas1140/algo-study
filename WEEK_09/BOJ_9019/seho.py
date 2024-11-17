from collections import deque


def rotateL(num):
    num = '000' + str(num)
    num = num[-4:]
    tmp = num[0]
    return int(num[1:] + tmp)


def rotateR(num):
    num = '000' + str(num)
    num = num[-4:]
    tmp = num[-1]
    return int(tmp + num[:-1])


def bfs(b):
    while True:

        num = dq.popleft()
        s = dslr.popleft()

        if visited[num]:
            continue
        if num == b:
            return s
        visited[num] = True

        # D
        if 2 * num > 9999:
            dq.append(2 * num % 10000)
        else:
            dq.append(2 * num)
        dslr.append(s + 'D')

        # S
        if num == 0:
            dq.append(9999)
        else:
            dq.append(num - 1)
        dslr.append(s + 'S')

        # L
        dq.append(rotateL(num))
        dslr.append(s + 'L')

        # R
        dq.append(rotateR(num))
        dslr.append(s + 'R')


T = int(input())

for _ in range(T):
    a, b = map(int, input().split())

    dq = deque([])
    dslr = deque([''])
    visited = [False for _ in range(10000)]

    dq.append(a)
    print(bfs(b))