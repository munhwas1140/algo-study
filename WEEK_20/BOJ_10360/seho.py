import sys
from collections import deque
input = sys.stdin.readline

def check():
    dp = [sys.maxsize for _ in range(n)]
    dp[0] = 0

    for i in range(n):
        for src in range(n):
            for dst, time in edge[src]:
                if dp[dst] > dp[src] + time and dp[src] != sys.maxsize:
                    dp[dst] = dp[src] + time
                    if i == n-1:
                        if bfs(dst):
                            return False
    return True

def bfs(node):
    visited = [False for _ in range(n)]
    visited[node] = True
    dq = deque([])
    dq.append(node)

    while dq:
        node = dq.popleft()
        if node == 0:
            return True
        for nextNode, _ in edge[node]:
            if visited[nextNode]: continue
            visited[nextNode] = True
            dq.append(nextNode)
    return False

T = int(input())

for t in range(T):
    n, m = map(int, input().split())
    pool = [i for i in range(n)]
    edge = [[] for _ in range(n)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        edge[a].append([b, c])

    if check():
        print(f'Case #{t+1}: not possible')
    else:
        print(f'Case #{t+1}: possible')