import sys
from collections import deque
input = sys.stdin.readline

dx = [1, 0, -1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

def bfs(sx, sy, sz, ex, ey, ez, ll, r, c):
    dq = deque([])
    dq.append([sx, sy, sz])
    visited[sz][sy][sx] = True
    ans = 0

    while dq:
        l = len(dq)
        for _ in range(l):
            x, y, z = dq.popleft()

            if x == ex and y == ey and z == ez:
                return ans

            for i in range(6):
                nx = x + dx[i]
                ny = y + dy[i]
                nz = z + dz[i]

                if nz < 0 or ny < 0 or nx < 0 or nz >= ll or ny >= r or nx >= c or board[nz][ny][nx] == '#' or visited[nz][ny][nx]: continue
                visited[nz][ny][nx] = True
                dq.append([nx, ny, nz])
        ans += 1
    return 0


while True:
    l, r, c = map(int, input().split())
    if l == 0:
        break

    board = [[] for _ in range(l)]
    visited = [[[False for _ in range(c)] for _ in range(r)] for _ in range(l)]

    sx, sy, sz = 0, 0, 0
    ex, ey, ez = 0, 0, 0
    for k in range(l):
        for i in range(r):
            tmp = list(input().strip())
            for j in range(c):
                if tmp[j] == 'S':
                    sx, sy, sz = j, i, k
                if tmp[j] == 'E':
                    ex, ey, ez = j, i, k
            board[k].append(tmp)
        tmp = input()

    ans = bfs(sx, sy, sz, ex, ey, ez, l, r, c)
    if ans == 0 :
        print("Trapped!")
    else:
        print("Escaped in {} minute(s).".format(ans))