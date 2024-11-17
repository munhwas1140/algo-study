import sys
input = sys.stdin.readline
N = int(input())
tree = [[] for _ in range(N+1)]
dp = [[0, 0] for _ in range(N+1)]
path = [[[] for _ in range(2)] for _ in range(N+1)]
W = [0] + list(map(int, input().split()))
visit = [False] * (N+1)

for _ in range(N-1):
    A, B = map(int, input().split())
    tree[A].append(B)
    tree[B].append(A)

# dp[node][0]: node가 독립 집합에 포함되지 않았을 때의 최대 가중치 합.
# dp[node][1]: node가 독립 집합에 포함되었을 때의 최대 가중치 합.
# path[node][0]: node가 독립 집합에 포함되지 않았을 때의 선택된 노드 목록.
# path[node][1]: node가 독립 집합에 포함되었을 때의 선택된 노드 목록.

def dfs(node):
    visit[node] = True
    dp[node][1] += W[node] #가중치 추가
    path[node][1].append(node) #node 포함한 경우, 그 노드를 path에 추가

    #재귀탐색
    for x in tree[node]:
        if not visit[x]: #방문 안했다면
            result = dfs(x)
            #dp랑 경로 업데이트 
            dp[node][0] += max(dp[x][0], dp[x][1])
            dp[node][1] += dp[x][0]

            path[node][1] += result[0]
            if dp[x][0] > dp[x][1]: #노드 포함 유무의 최대 가중치 합 비교. 
                path[node][0] += result[0]
            else:
                path[node][0] += result[1]

    return path[node]


p = dfs(1)
#가중치 더 큰 거 비교 후 정렬, 출력
if dp[1][0] > dp[1][1]: 
    print(dp[1][0])
    p[0].sort()
    for i in p[0]:
        print(i, end=' ')
else:
    print(dp[1][1])
    p[1].sort()
    for i in p[1]:
        print(i, end=' ')