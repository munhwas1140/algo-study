import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

def dfs(sx, ex, sy, ey, dire):
    jewel = 0
    imp = 0

    for i in range(sx, ex):
        for j in range(sy, ey):
            if board[j][i] == 2: jewel += 1
            elif board[j][i] == 1: imp += 1

    if jewel == 0: return 0
    elif jewel == 1 and imp == 0: return 1

    ans = 0

    for i in range(sx, ex):
        for j in range(sy, ey):
            if board[j][i] == 1:
                if dire != 0:
                    for y in range(sy, ey):
                        if board[y][i] == 2:
                            break
                    else:
                        ans += dfs(sx, i, sy, ey, 0) * dfs(i+1, ex, sy, ey, 0)
                if dire != 1:
                    for x in range(sx, ex):
                        if board[j][x] == 2:
                            break
                    else :
                        ans += dfs(sx, ex, sy, j, 1) * dfs(sx, ex, j+1, ey, 1)

    return ans

ans = dfs(0, n, 0, n, -1)
if ans == 0:
    print(-1)
else:
    print(ans)