import sys
from collections import deque

input = sys.stdin.readline

MAX = 10**8

t = int(input())
for case in range(1, t+1):
    n, m = map(int, input().split())
    
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a].append((b, c))
    
    def bellman():
        negative = []
        dist = [MAX] * n
        dist[0] = 0
        
        for i in range(1, n+1):
            for curr in range(n):
                for nxt, time in graph[curr]:
                    if dist[curr] < MAX and dist[curr] + time < dist[nxt]:
                        dist[nxt] = dist[curr] + time
                        
                        if i == n:
                            negative.append(nxt)
        
        def bfs(start):
            visited = [False] * n
            visited[start] = True
            queue = deque([start])
            
            while queue:
                curr = queue.popleft()
                
                if curr == 0:
                    return True
                
                for nxt, _ in graph[curr]:
                    if not visited[nxt]:
                        visited[nxt] = True
                        queue.append(nxt)
            
            return False
        
        for node in negative:
            if bfs(node):
                return True
        
        return False
        
    result = "possible" if bellman() else "not possible"
    print(f"Case #{case}: {result}")