import sys
from collections import deque
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n = int(input())
board = [list(map(int, list(input().strip()))) for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]

def bfs(x, y):
    dq = deque([])
    visited[y][x] = True
    dq.append((x, y))
    cnt = 1

    while dq:
        x, y = dq.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= n or visited[ny][nx] or board[ny][nx] == 0: continue

            visited[ny][nx] = True
            dq.append((nx, ny))
            cnt += 1

    return cnt

ans = []
for i in range(n):
    for j in range(n):
        if board[i][j] == 1 and not visited[i][j]:
            ans.append(bfs(j, i))

print(len(ans))
ans.sort()
for i in ans:
    print(i)