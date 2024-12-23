import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
bc, bv = map(int, input().split())

graph = []
parent = [i for i in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph.append((-c, a, b))
heapq.heapify(graph)
def find(x):
    if parent[x] == x:
        return parent[x]
    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)

    if a < b : parent[b] = a
    else : parent[a] = b

while True:
    c, a, b = heapq.heappop(graph)

    if find(a) != find(b):
        union(a, b)

    if find(bc) == find(bv):
        print(-c)
        break