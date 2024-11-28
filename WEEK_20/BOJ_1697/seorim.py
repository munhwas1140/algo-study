import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().split())
MAX = max(n, k) * 2 + 1

queue = deque([(n, 0)])
visited = [False] * MAX

while queue:
    curr, time = queue.popleft()
    
    if curr == k:
        print(time)
        break
    
    nexts = [curr - 1, curr + 1, curr * 2]
    for nxt in nexts:
        if 0 <= nxt and nxt < MAX and not visited[nxt]:
            visited[nxt] = True
            queue.append((nxt, time+1))