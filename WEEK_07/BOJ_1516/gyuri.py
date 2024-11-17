import sys
from collections import deque

input = sys.stdin.readline
n = int(input())

# 노드와 간선의 정보 저장
building = [[] for _ in range(n + 1)]
# 각 노드의 진입차수 저장
indegree = [0] * (n + 1)
# 건물 짓는데 걸리는 시간
cost = [0] * (n + 1)

for i in range(1, n + 1):
    data = list(map(int, input().split()))[:-1]
    cost[i] = data[0]
    building_data = data[1:]
    for j in building_data:
        building[j].append(i)
        indegree[i] += 1

# 위상 정렬 함수
def topology_sort():
    result = [0] * (n + 1)
    q = deque()

    for i in range(1, n + 1):
        if indegree[i] == 0: # 진입차수가 0인 정점이라면
            q.append(i) 

    while q:
        now = q.popleft()
        result[now] += cost[now]
        for b in building[now]:
            indegree[b] -= 1 
            result[b] = max(result[b], result[now])
            if indegree[b] == 0:
                q.append(b)

    return result


answer = topology_sort()
for i in range(1, n + 1):
    print(answer[i])