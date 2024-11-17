import sys
sys.setrecursionlimit(10000)

# 상하좌우 이동을 위한 방향 벡터
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def dfs(y, x):
    stack = [(y, x)]
    local_max_level = 0
    farthest_point = (y, x)
    
    while stack:
        y, x = stack.pop()
        
        if visited[y][x] > local_max_level:
            farthest_point = (y, x)
            local_max_level = visited[y][x]
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if 0 <= ny < m and 0 <= nx < n and visited[ny][nx] == 0 and labyrinth[ny][nx] == '.':
                visited[ny][nx] = visited[y][x] + 1
                stack.append((ny, nx))
    
    return local_max_level, farthest_point

def setPos():
    global max_level, py, px
    max_level = 0
    for i in range(m):
        for j in range(n):
            if labyrinth[i][j] == '.' and visited[i][j] == 0:
                visited[i][j] = 1
                _, (py, px) = dfs(i, j)
                return

# 입력 처리
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    labyrinth = [list(input().strip()) for _ in range(m)]
    
    py, px = -1, -1
    visited = [[0] * n for _ in range(m)]
    
    setPos()
    
    visited = [[0] * n for _ in range(m)]
    visited[py][px] = 1
    max_length, _ = dfs(py, px)
    
    print(f"Maximum rope length is {max_length - 1}.")
