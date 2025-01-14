import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n+1)]
leaf = set()
for i in range(1, n+1):
    leaf.add(i)
for _ in range(n-1):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])
    if a in leaf:
        leaf.remove(a)
leaf.add(1)
node = list(leaf)[0]
ans = 0

for _ in range(2):
    dq = deque([[node, 0]])
    visited = [False for _ in range(n+1)]
    visited[node] = True

    while dq:
        cur, dist = dq.popleft()
        if cur in leaf:
            if ans < dist:
                node = cur
                ans = dist

        for nextNode, w in graph[cur]:
            if visited[nextNode]: continue

            tmp = dist + w
            visited[nextNode] = True
            dq.append([nextNode, tmp])

print(ans)