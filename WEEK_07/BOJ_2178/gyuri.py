from collections import deque
import sys
input = sys.stdin.readline
n, m = map(int, input().split())

graph = []

for _ in range(n):
    graph.append(list(map(int, input())))

def BFS(x, y):
    # 상, 하, 좌, 우
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]

    queue = deque()
    queue.append((x,y))

    while queue:
        x, y = queue.popleft()
        # 현재 위치에서 4가지 방향 위치 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 위치 벗어나면 안되므로 조건 추가
            if nx<0 or nx>=n or ny<0 or ny>=m:
                continue
            # 벽이므로 진행 불가
            if graph[nx][ny]==0:
                continue
            # 벽이 아니므로 이동 가능
            if graph[nx][ny]==1:
                graph[nx][ny] = graph[x][y]+1
                queue.append((nx,ny))

    # 마지막 값에서 카운트 값 뽑기
    return graph[n-1][m-1]

print(BFS(0,0))