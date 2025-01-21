import sys
from collections import deque
input = sys.stdin.readline

def bfs(node):
    dq = deque([])
    visited = [False for _ in range(n)]

    for i in graph[node]:
        dq.append(i)

    while dq:
        cur = dq.popleft()
        if visited[cur]: continue
        ans[node][cur] = 1
        visited[cur] = True
        for i in graph[cur]:
            dq.append(i)

n = int(input())
ans = [[0 for _ in range(n)] for _ in range(n)]
graph = [[] for _ in range(n)]
for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(n):
        if tmp[j] == 1:
            graph[i].append(j)

for i in range(n):
    bfs(i)
    print(*ans[i])