from collections import deque
n, t, g = map(int, input().split())

def check(num, cnt):
    if num < 0 or num > 99999 or dp[num] != -1:
        return

    dp[num] = cnt
    dq.append(num)

cnt = 0
dq = deque([])
dq.append(n)
dp = [-1 for _ in range(100000)]
dp[n] = 0
while cnt != t:
    l = len(dq)
    cnt += 1
    for _ in range(l):
        num = dq.popleft()
        numA = num+1
        check(numA, cnt)

        numB = 2*num
        if numB < 100000:
            numB -= (10 ** (len(str(numB))-1))
            check(numB, cnt)

if dp[g] == -1:
    print("ANG")
else:
    print(dp[g])

