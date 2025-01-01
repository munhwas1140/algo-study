import sys
from collections import deque
input = sys.stdin.readline
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

m, n = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dq = deque([])
ans = 0
cnt = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            dq.append((i, j))
            cnt += 1
        if board[i][j] == -1:
            cnt += 1

while dq:
    l = len(dq)

    for _ in range(l):
        y, x = dq.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n or board[ny][nx] == -1 or board[ny][nx] == 1: continue

            board[ny][nx] = 1
            dq.append((ny, nx))
            cnt += 1
    ans += 1

if cnt != m*n:
    print(-1)
else:
    print(ans-1)