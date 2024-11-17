import sys
input = sys.stdin.readline
n,m = map(int, input().split())

if n > m:
    n, m = m, n
dp = [[-1] * (m + 1) for _ in range(m + 1)]
def check(n, m):
    if n == 1 and m == 1:
        return 2 #종료
    if dp[n][m] != -1:
        return dp[n][m]
    dp[n][m] = 0

    # y에 대하여
    for i in range(1, m):  # m을 1에서 m-1로 나누기
        if check(i, m - i) in [0, 2]:
            dp[n][m] = 1
            return 1

    # x에 대하여
    for i in range(1, n):  # n을 1에서 n-1로 나누기
        if check(i, n - i) in [0, 2]:
            dp[n][m] = 1
            return 1
    return dp[n][m]

if check(n, m) == 1:
    print("A")
else:
    print("B")