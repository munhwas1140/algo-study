import sys
input = sys.stdin.readline

T = int(input())
num = [0, 0, 1, 7, 4, 2, 0, 8]
dp = [0, 9, 1, 7, 4, 2, 6, 8] + [sys.maxsize for _ in range(8, 101)]
for i in range(8, 101):
    for j in range(2, 8):
        dp[i] = min(dp[i], dp[i - j]*10 + num[j])

for _ in range(T):
    n = int(input())
    if n % 2 == 0:
        s = '1' * (n//2)
    else:
        s = '7'
        s = s + '1' * ((n//2)-1)
    maxn = int(s)
    print(dp[n], maxn)

 # , 10




# [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
