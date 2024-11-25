import sys
from collections import deque
from collections import defaultdict
input = sys.stdin.readline

n, m, k = map(int, input().split())
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
board = []
for _ in range(n):
    board.append(list(input().strip()))
ans = defaultdict(int)

def bfs():
    dq = deque([])
    dq.append([n-1, 0, 1, [(n-1, 0)]])
    while len(dq) != 0:
        y, x, dist, visited = dq.popleft()
        if x == m-1 and y == 0:
            ans[dist] += 1

        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y

            if nx < 0 or ny < 0 or nx >= m or ny >= n: continue
            if (ny, nx) in visited: continue
            if board[ny][nx] == 'T': continue
            tmp = visited.copy()
            tmp.append((ny, nx))
            dq.append([ny, nx, dist+1, tmp])
bfs()

print(ans[k])