N, e, w, s, n = map(int, input().split())
p = [e/100, w/100, s/100, n/100]
d = [[1,0], [-1,0], [0,-1], [0, 1]]
visited = [[False for _ in range(2*N + 1)] for _ in range(2*N + 1)]
visited[N][N] = True
ans = 0

def dfs(cnt, prob, x, y, visited):
    global ans

    if cnt == N:
        ans += prob
        return

    for i in range(4):
        nx = x + d[i][0]
        ny = y + d[i][1]

        if visited[nx+N][ny+N] or p[i] == 0: continue
        prob *= p[i]
        visited[nx+N][ny+N] = True
        dfs(cnt+1, prob, nx, ny, visited)
        visited[nx + N][ny + N] = False
        prob /= p[i]

dfs(0, 1, 0, 0, visited)
print(ans)
