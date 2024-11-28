import sys

input = sys.stdin.readline

n, k = map(int, input().split())
dp = [1] + [0] * k
coins = [int(input()) for _ in range(n)]

for i, coin in enumerate(coins):
    for money in range(1, k+1):
        if money - coin >= 0:
            dp[money] += dp[money-coin]

print(dp[k])