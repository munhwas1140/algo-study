import math

#노드의 루트를 찾음
def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

# 노드를 한 집합으로 합침
def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n = int(input())
parent = [i for i in range(n + 1)]

stars = []
edges = []
result = 0

for _ in range(n):
    x, y = map(float, input().split())
    stars.append((x, y))

#모든 별 쌍에 대해 거리 계산
for i in range(n - 1):
    for j in range(i + 1, n):
        edges.append((math.sqrt((stars[i][0] - stars[j][0])**2 + (stars[i][1] - stars[j][1])**2), i, j))

edges.sort()

#크루스칼 알고리즘으로 최소 신장 트리 구성
for edge in edges:
    cost, x, y = edge

    if find_parent(x) != find_parent(y):
        union_parent(x, y)
        result += cost

print(round(result, 2))