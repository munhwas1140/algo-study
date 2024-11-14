import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
board = [[0 for _ in range(m+1)]]
for _ in range(1, n+1):
    li = [0] + list(map(int, input().split()))
    for i in range(1, m+1):
        li[i] += li[i-1]
    board.append(li)

for i in range(1, n+1):
    for j in range(1, m+1):
        board[i][j] += board[i-1][j]

for _ in range(k):
    a, b, c, d = map(int, input().split())
    print((board[c][d] - board[c][b-1] - board[a-1][d] + board[a-1][b-1])//((c-a+1) * (d-b+1)))

# 22
# 11
# 14

# 47
# 78 - 35 = 43 + 4