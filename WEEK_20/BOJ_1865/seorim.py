import sys

input = sys.stdin.readline
MAX = 10**8

"""
놓쳤던 부분
1. 처음에 어차피 사이클만 찾을 거니까 1번을 임의로 출발로 해도 상관없을 것이라 생각
그러나, 1번과 나머지 그래프가 연결되어 있을 것이라는 보장이 없다
2. 모든 노드를 출발점으로 삼아, n회 벨만 포드 진행 -> 시간초과
사이클만 찾을 것이므로, 연결되어 있지 않더라도 그냥 MAX에 시간 더해주고 계속 검사하면
초기 노드를 설정하지 않고도 사이클을 찾을 수 있다.
주의할 점은 inf로 설정하면, inf - alpha = inf이므로 음수 사이클이 있더라도 가중치가 갱신되지 않는다.
우리의 목적은 어디서 출발하든 음수 사이클만 찾으면 되기 때문에 작게나마 변해야 한다.
https://wikidocs.net/225180
"""

t = int(input())
for _ in range(t):
    n, m, w = map(int, input().split())
    graph = []
    
    for _ in range(m):
        s, e, t = map(int, input().split())
        graph.append((s, e, t))
        graph.append((e, s, t))
    
    for _ in range(w):
        s, e, t = map(int, input().split())
        graph.append((s, e, -t))
        
    def bellman():
        dist = [MAX] * (n+1)
        
        for i in range(1, n+1):
            for curr, nxt, time in graph:
                if dist[curr] + time < dist[nxt]:
                    dist[nxt] = dist[curr] + time
                    
                    if i == n:
                        return True
                    
        return False
    
    print("YES" if bellman() else "NO")