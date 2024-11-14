import sys
from collections import deque
input = sys.stdin.readline

n, now, goal, u, d = map(int, input().split())
visited = [False for _ in range(n+1)]
dq = deque([])

dq.append(now)
visited[now] = True

def bfs():
    ans = 0
    while dq:
        l = len(dq)
        for _ in range(l):
            cur = dq.popleft()
            if cur == goal:
                return ans
            for i in [u, -d]:
                ncur = cur + i

                if ncur < 1 or ncur > n or visited[ncur]: continue
                dq.append(ncur)
                visited[ncur] = True
        ans += 1
    return 'use the stairs'

print(bfs())