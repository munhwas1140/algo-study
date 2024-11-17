# BOJ1922 네트워크 연결

import sys
input = sys.stdin.readline

def find(a):
    global graph
    if graph[a] == a: return a

    graph[a] = find(graph[a])
    return graph[a]

def union(a, b):
    a = find(a)
    b = find(b)

    if (a>b): graph[a] = b
    elif (a<b): graph[b] = a

n = int(input())
m = int(input())
graph = [i for i in range(n+1)]
cost = []

ans = 0
for _ in range(m):
    cost.append(list(map(int, input().split())))

cost.sort(key=lambda x : x[2])

for i in range(m):
    a, b, c = cost[i]

    if find(a) != find(b):
        union(a, b)
        ans += c

    if len(set(graph)) == 2:
        break
print(ans)