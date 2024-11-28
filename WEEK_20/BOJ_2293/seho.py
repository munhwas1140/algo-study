import sys
input = sys.stdin.readline

n, k = map(int, input().split())
dp = [0 for _ in range(k+1)]
dp[0] = 1
for _ in range(n):
    c = int(input())
    for i in range(c, k+1):
        dp[i] = dp[i] + dp[i-c]

print(dp[-1])