N, L, I = map(int, input().split())

dp = [[0 for _ in range(L+1)] for _ in range(N)]
for i in range(N):
    dp[i][0] = 1

for i in range(1, N):
    for j in range(1, L+1):
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

ans = ''
for i in range(N):
    s = sum(dp[N-i-1][:L+1])
    if s < I:
        I -= s
        L -= 1
        ans += '1'
    else:
        ans += '0'

print(ans)
# n = 1
# 0 1

# n = 2
# 1 2

# n = 3
# 1 2 2 3

# n = 4
# 1 2 2 3 2 3 3 4

# n = 5
# 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5

# 0 1  2  3 4

# 1 0  0  0 0 ... N = 0 1 1
# 1 1  0  0 0 ... N = 1 2 1
# 1 2  1  0 0 ... N = 2 4 0
# 1 3  3  1 0 ... N = 3 7 0
# 1 4  6  4 1 ... N = 4 15 1
# 1 5 10 10       N = 5


# 0
# 1
# 10
# 11
# 100
# 101
# 110
# 111