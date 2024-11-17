import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def bfs(a, b):
    dq = deque([])

    dq.append([a, b, 0])
    visited[a][b] = True

    while len(dq) != 0 :
        tmp = dq.popleft()
        x = tmp[1]
        y = tmp[0]

        for i in range(4):
            l = tmp[2]
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n or visited[ny][nx] or pyramid[ny][nx] == '#': continue

            visited[ny][nx] = True
            l += 1
            dq.append([ny, nx, l])
            maxli[0] = ny
            maxli[1] = nx
            maxli[2] = l



for _ in range(T):
    m, n = map(int, input().split())

    pyramid = []
    maxli = [0, 0, 0]

    visited = [[False for _ in range(m)] for _ in range(n)]
    for _ in range(n):
        pyramid.append(list(input()))

    for i in range(n):
        for j in range(m):
            if pyramid[i][j] == '.':
                bfs(i, j)
                break

    visited = [[False for _ in range(m)] for _ in range(n)]
    bfs(maxli[0], maxli[1])

    print("Maximum rope length is {}.".format(maxli[2]))

#######
#######
###..##
###.###
#######
#######