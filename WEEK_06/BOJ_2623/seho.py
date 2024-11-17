import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
outd = [0 for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for _ in range(m):
    singer = list(map(int, input().split()))[1:]

    for i in range(1, len(singer)):
        graph[singer[i-1]].append(singer[i])
        outd[singer[i]] += 1

dq = deque([])
for i in range(1, n+1):
    if outd[i] == 0:
        dq.append(i)

ans = []
while len(dq) != 0:
    num = dq.popleft()
    if visited[num]: continue

    ans.append(num)
    visited[num] = True

    for child in graph[num]:
        outd[child] -= 1
        if outd[child] == 0:
            dq.append(child)

if len(ans) == n:
    for a in ans:
        print(a)
else:
    print(0)