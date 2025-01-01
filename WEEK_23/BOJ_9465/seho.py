import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    sticker = [list(map(int, input().split())) for _ in range(2)]

    dp = [[0 for _ in range(n)] for _ in range(2)]
    dp[0][0] = sticker[0][0]
    dp[1][0] = sticker[1][0]

    for i in range(1, n):
        dp[0][i] = max(dp[0][i-1], dp[1][i-1] + sticker[0][i])
        dp[1][i] = max(dp[1][i-1], dp[0][i-1] + sticker[1][i])

    print(max(dp[0][-1], dp[1][-1]))

# 50 10 100 20 40
# 30 50 70 10 60

# 50 40  200 130 250
# 30 100 110 210 260

# 10 30 10 50 100 20 40
# 20 40 30 50 60 20 80

# 10 50 60 130 210 210 270
# 20 50 80 110 190 230 290