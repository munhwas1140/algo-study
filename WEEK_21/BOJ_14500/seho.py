import sys
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

def check(y, x):
    polio = [[(y, x), (y, x+1), (y, x+2), (y, x+3)], # ㅡ
          [(y, x), (y+1, x), (y+2, x), (y+3, x)], # ㅣ
          [(y, x), (y, x+1), (y+1, x), (y+1, x+1)], # ㅁ
          [(y, x), (y+1, x), (y+2, x), (y+2, x+1)], # └
          [(y, x), (y, x+1), (y, x+2), (y-1, x+2)], # ㄴ 대칭
          [(y, x), (y-1, x), (y-2, x), (y-2, x-1)], # ┐
          [(y, x), (y, x-1), (y, x-2), (y+1, x-2)],
          [(y, x), (y, x+1), (y-1, x+1), (y-2, x+1)], # ┘
          [(y, x), (y-1, x), (y-1, x-1), (y-1, x-2)], #
          [(y, x), (y, x-1), (y+1, x-1), (y+2, x-1)], # ┌
          [(y, x), (y+1, x), (y+1, x+1), (y+1, x+2)], #
          [(y, x), (y+1, x), (y+1, x+1), (y+2, x+1)], # h
          [(y, x), (y+1, x), (y+1, x-1), (y+2, x-1)], # h대징
          [(y, x), (y, x-1), (y-1, x-1), (y-1, x-2)], # s대칭
          [(y, x), (y, x+1), (y-1, x+1), (y-1, x+2)], # s
          [(y, x), (y, x+1), (y+1, x+1), (y, x+2)], # ㅜ
          [(y, x), (y-1, x), (y-1, x+1), (y-2, x)], # ㅏ
          [(y, x), (y, x-1), (y-1, x-1), (y, x-2)], # ㅗ
          [(y, x), (y+1, x), (y+1, x-1), (y+2, x)] # ㅓ
          ]
    ret = 0
    for i in range(len(polio)):
        ans = 0
        for r, c in polio[i]:
            if r < 0 or c < 0 or r >= n or c >= m:
                ans = 0
                break
            ans += board[r][c]
        ret = max(ans, ret)
    return ret

ans = 0
for i in range(n):
    for j in range(m):
        ans = max(ans, check(i, j))

print(ans)