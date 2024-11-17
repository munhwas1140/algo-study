import sys

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

r, c = map(int, input().split())

visited = [False] * 26
board = [input() for _ in range(r)]
cnt = 0
maxcnt = 0

def dfs(x, y, cnt):
    global maxcnt
    cnt += 1
    maxcnt = max(cnt, maxcnt)
    visited[ord(board[y][x]) - 65] = True

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx >= c or ny >= r or nx < 0 or ny < 0 or visited[ord(board[ny][nx]) - 65]: continue
        dfs(nx, ny, cnt)
    cnt -= 1
    visited[ord(board[y][x]) - 65] = False

dfs(0, 0, cnt)

print(maxcnt)