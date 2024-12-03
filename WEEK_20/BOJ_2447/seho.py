n = int(input())
board = [['*' for _ in range(n)] for _ in range(n)]

def daq(si, sj, n):
    d = n//3

    for i in range(si, si+n, d):
        for j in range(sj, sj+n, d):
            if j == sj + d and i == si + d:
                for a in range(i, i+d):
                    for b in range(j, j+d):
                        board[a][b] = ' '
            else:
                if d > 1:
                    daq(i, j, d)

daq(0, 0, n)
for i in range(n):
    for j in range(n):
        print(board[i][j], end="")
    print()
# 9, 9
# 3, 3 (0-8)(0-8) / 12, 3 (9-18)(0-8) / 21, 3 (19-27)(0-8)
# 3, 12 / 12, 12 / 21, 12