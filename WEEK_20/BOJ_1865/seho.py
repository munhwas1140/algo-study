import sys
input = sys.stdin.readline

T = int(input())

def check():
    dp = [sys.maxsize for _ in range(n)]
    dp[0] = 0
    for i in range(n):
        for stnode, node, time in road:
            if dp[stnode] == sys.maxsize:
                dp[stnode] = 0
            if dp[stnode] != sys.maxsize and time + dp[stnode] < dp[node]:
                dp[node] = time + dp[stnode]
                if i == n-1:
                    return "YES"
    return "NO"

for _ in range(T):
    n, m, w = map(int, input().split())

    road = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        road.append([s-1, e-1, t])
        road.append([e-1, s-1, t])
    for _ in range(w):
        s, e, t = map(int, input().split())
        road.append([s-1, e-1, -t])



    print(check())