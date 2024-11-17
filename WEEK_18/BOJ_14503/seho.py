import sys
from collections import Counter
input = sys.stdin.readline

dire = [[0, -1], [1, 0], [0, 1], [-1, 0]]

n, m = map(int, input().split())
y, x, d = map(int, input().split())
board = []
stop_rec = False
for _ in range(n):
    board.append(list(map(int, input().split())))

def move(x, y, d):
    x += dire[d][0]
    y += dire[d][1]

    return x, y

def dfs(x, y, d):
    global stop_rec

    if stop_rec:
        return

    if board[y][x] == 1:
        return

    if board[y][x] == 0:
        board[y][x] = 2

    flag = False

    for i in range(4):
        nx = x + dire[i][0]
        ny = y + dire[i][1]
        if nx < 0 or ny < 0 or nx >= m or ny >= n: continue
        if board[ny][nx] == 0:
            flag = True
            break

    if not flag:
        nd = (d + 2) % 4
        nx, ny = move(x, y, nd)

        if board[ny][nx] == 1:
            stop_rec = True
            return
        else:
            dfs(nx, ny, d)
    else:
        while True:
            d = (d+3)%4
            nx, ny = move(x, y, d)
            if board[ny][nx] == 0:
                break
        dfs(nx, ny, d)

dfs(x, y, d)

# for i in range(n):
#     print(*board[i])

li = sum(board, [])
print(Counter(li)[2])