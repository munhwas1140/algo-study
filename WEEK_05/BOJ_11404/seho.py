import sys

input = sys.stdin.readline

n = int(input())
m = int(input())

dist = [[sys.maxsize for _ in range(n)] for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1

    dist[a][b] = min(c, dist[a][b])

for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(n):
    for j in range(n):
        if i == j :
            print(0, end=' ')
        elif dist[i][j] >= sys.maxsize:
            print(0, end=' ')
        else:
            print(dist[i][j], end=' ')
    print()
