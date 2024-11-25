import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

def bfs(hx, hy, px, py):
    dq = deque([])
    visited = [False for _ in range(len(convi))]
    for i in range(len(convi)):
        cx, cy = convi[i][0], convi[i][1]
        if abs(hx-cx) + abs(hy-cy) <= 1000:
            if cx == px and cy == py:
                return True
            visited[i] = True
            dq.append([cx, cy])
    while dq:
        nx, ny = dq.popleft()

        for i in range(len(convi)):
            if visited[i]: continue
            cx, cy = convi[i][0], convi[i][1]
            if abs(nx - cx) + abs(ny - cy) <= 1000:
                if cx == px and cy == py:
                    return True
                visited[i] = True
                dq.append([cx, cy])
    return False

for _ in range(T):
    n = int(input())
    hx, hy = map(int, input().split())
    convi = []
    for _ in range(n):
        convi.append(list(map(int, input().split())))
    px, py = map(int, input().split())
    convi.append([px, py])

    if bfs(hx, hy, px, py):
        print("happy")
    else:
        print("sad")


# 한 번에 갈 수 있는 거리 : 1000
