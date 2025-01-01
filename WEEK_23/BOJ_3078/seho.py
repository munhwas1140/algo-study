import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
dq = deque([len(input().strip()) for _ in range(n)])
length = [0 for _ in range(21)]

for i in range(k):
    length[dq[i]] += 1
ans = 0
while dq:
    a = dq.popleft()
    length[a] -= 1
    if len(dq) >= k:
        length[dq[k-1]] += 1
    ans += length[a]

print(ans)
# 7 5 6 5 7 6
