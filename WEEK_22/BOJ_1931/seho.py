import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
board.sort(key=lambda x:(x[0], x[1]))

start = board[0][0]
end = board[0][1]
cnt = 1

for i in range(1, n):
    if board[i][1] < end:
        end = board[i][1]
    elif board[i][0] >= end:
        cnt += 1
        end = board[i][1]

print(cnt)