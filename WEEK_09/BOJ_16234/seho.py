import sys
from collections import deque

input = sys.stdin.readline

n, l, r = map(int, input().split())
population = []
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for _ in range(n):
    tmp = list(map(int, input().split()))
    population.append(tmp)

def checkGuild(a, b, guildNum):
    dq = deque([])
    dq.append([a, b])

    cnt = 1
    total = population[a][b]
    while len(dq) != 0 :
        x = dq[0][1]
        y = dq[0][0]
        dq.popleft()
        guild[y][x] = guildNum

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if ny < 0 or nx < 0 or ny >= n or nx >= n or guild[ny][nx] != 0: continue

            if l <= abs(population[ny][nx] - population[y][x]) <= r :
                guild[ny][nx] = guildNum
                cnt += 1
                total += population[ny][nx]
                dq.append([ny, nx])

    guildDict[guildNum] = [cnt, total]

ans = 0
while True :

    # 연합국 표시.
    guild = [[0 for _ in range(n)] for _ in range(n)]
    guildDict = {}
    gNum = 0
    for i in range(n):
        for j in range(n):
            if guild[i][j] == 0:
                gNum += 1
                checkGuild(i, j, gNum)

    # 인원 이동하기
    for i in range(n):
        for j in range(n):
            guildNum = guild[i][j]
            tmp = guildDict[guildNum]
            population[i][j] = tmp[1] // tmp[0]

    if guildNum == n*n:
        break

    ans += 1

print(ans)