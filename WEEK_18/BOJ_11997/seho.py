import sys

input = sys.stdin.readline

n = int(input())
coord = []
xs = set()
ys = set()

for _ in range(n):
    x, y = map(int, input().split())
    coord.append([x, y])
    xs.add(x)
    ys.add(y)

board = [[0 for _ in range(len(ys)+1)] for _ in range(len(xs)+1)]
px = sorted(list(xs))
py = sorted(list(ys))

for x, y in coord:
    board[px.index(x)+1][py.index(y)+1] = 1

for i in range(1, len(xs)+1):
    for j in range(1, len(ys)+1):
        board[i][j] += board[i][j-1]

for i in range(1, len(xs)+1):
    for j in range(1, len(ys)+1):
        board[i][j] += board[i-1][j]

ans = sys.maxsize
for i in range(1, len(xs)+1):
    for j in range(1, len(ys)+1):
        ans = min(ans, max(board[i][j], board[len(xs)][j] - board[i][j], board[i][len(ys)] - board[i][j], board[-1][-1] - board[len(xs)][j] - board[i][len(ys)] + board[i][j]))

print(ans)