import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

graph = []
isOutside = [[False for _ in range(m)] for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
for _ in range(n):
    graph.append(list(map(int, input().split())))


def checkInside():
    global isOutside
    dq = deque([])
    dq.append((0, 0))

    isOutside = [[False for _ in range(m)] for _ in range(n)]
    while len(dq) != 0:
        node = dq.popleft()
        x = node[1]
        y = node[0]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n: continue
            if graph[ny][nx] == 1:
                isOutside[ny][nx] = True
                continue
            if isOutside[ny][nx]: continue
            isOutside[ny][nx] = True
            dq.append((ny, nx))


def checkMeltingCheese(y, x):
    cnt = 0

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= m or ny >= n: continue

        if graph[ny][nx] == 0 and isOutside[ny][nx]:
            cnt += 1
    if cnt > 1:
        graph[y][x] = 2


ans = 0

while True:
    check = False
    for i in range(n):
        for j in range(m):
            if graph[i][j] != 0:
                check = True
                break
        if check : break
    if not check:
        break
    checkInside()
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                checkMeltingCheese(i, j)
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 2:
                graph[i][j] = 0

    ans += 1

print(ans)