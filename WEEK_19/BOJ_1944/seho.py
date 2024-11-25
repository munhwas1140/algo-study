import sys
from collections import deque
import heapq

input = sys.stdin.readline

n, m = map(int, input().strip().split())
board = []
coord = []
m += 1
parent = [i for i in range(m)]

dist = []
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
for i in range(n):
    li = list(input())
    board.append(li)
    for j in range(n):
        if li[j] == 'S' or li[j] == 'K':
            coord.append((i, j))


def bfs(sx, sy, cid):
    d = 0
    visited = [[False for _ in range(n)] for _ in range(n)]
    dq = deque([[sy, sx]])
    visited[sy][sx] = True

    while dq:
        l = len(dq)
        for _ in range(l):
            y, x = dq.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx < 0 or ny < 0 or nx >= n or ny >= n or visited[ny][nx]: continue
                if board[ny][nx] == '1': continue
                if board[ny][nx] == 'S' or board[ny][nx] == 'K':
                    idx = coord.index((ny, nx))
                    heapq.heappush(dist, [d + 1, [cid, idx]])
                visited[ny][nx] = True
                dq.append([ny, nx])
        d += 1
    for i in range(m):
        y, x = coord[i]
        if not visited[y][x]:
            return False
    return True


def find(x):
    if parent[x] == x: return parent[x]

    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


for i in range(m):
    sy, sx = coord[i]
    if not bfs(sx, sy, i):
        print(-1)
        exit()


ans = 0
while dist:
    d, c = heapq.heappop(dist)
    x, y = c
    if find(x) != find(y):
        union(x, y)
        ans += d
print(ans)
