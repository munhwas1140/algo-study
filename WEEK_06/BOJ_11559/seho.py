import sys
from collections import deque

input = sys.stdin.readline

field = []
for _ in range(12):
    field.append(list(input().rstrip()))
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def bfs(y, x):
    visited = [[False for _ in range(6)] for _ in range(12)]
    dq = deque([])
    dq.append((y, x))
    cnt = 1
    loc = [(y, x)]

    while len(dq) != 0:
        node = dq.pop()
        x = node[1]
        y = node[0]
        color = field[y][x]
        visited[y][x] = True

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= 6 or ny >= 12 or visited[ny][nx] == True or color != field[ny][nx]: continue

            visited[ny][nx] = True
            cnt += 1
            dq.append((ny, nx))
            loc.append((ny, nx))

    return loc

def bomb():
    cnt = 0
    for i in range(12):
        for j in range(6):
            if field[i][j] != '.':
                loc = bfs(i, j)

                if len(loc) > 3:
                    for coord in loc:
                        x = coord[1]
                        y = coord[0]

                        field[y][x] = '.'
                    cnt = 1
    return cnt

def gravity():
    for i in range(6):
        j = 11
        while j != 0:
            if field[j][i] == '.' and field[j-1][i] != '.':
                field[j][i], field[j-1][i] = field[j-1][i], field[j][i]
                if j != 11: j += 1
            else : j -= 1

ans = 0
check = 1
while check :
    check = bomb()
    gravity()
    ans += check

# for i in range(12):
#     print(*field[i])

print(ans)