import sys
import heapq
input = sys.stdin.readline

n, m, f, s, t = map(int, input().split())
cities = [i for i in range(n)]
roads = [[] for _ in range(n)]
flights = []

def bfs(s):
    costs = [sys.maxsize for _ in range(n)]
    costs[s] = 0
    hq = [[costs[s], s]]

    while hq:
        node = heapq.heappop(hq)[1]
        for nextNode, c in roads[node]:
            if costs[nextNode] > costs[node] + c:
                costs[nextNode] = costs[node] + c
                heapq.heappush(hq, [costs[nextNode], nextNode])
    return costs

for _ in range(m):
    a, b, c = map(int, input().split())
    roads[a].append([b, c])
    roads[b].append([a, c])

for _ in range(f):
    flights.append(list(map(int, input().split())))

start = bfs(s)
end = bfs(t)
ans = start[t]
for a, b in flights:
    ans = min(ans, start[a] + end[b])

print(ans)

