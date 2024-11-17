n, k = map(int, input().split())

# 1 1 1 1 1 1
# 1 2 3 4 5
# 1 3 6 10
# 1 4 10
# 1 5
# 1

# 1 1 2 6 10
dp = [[1 for _ in range(n+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007

print(dp[n-k][k])