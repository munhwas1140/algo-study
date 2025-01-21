import sys
input = sys.stdin.readline

n = int(input())
li = []
hh = 0
hl = 0
for _ in range(n):
    l, h = map(int, input().split())
    li.append([l, h])
    if hh < h:
        hh = h
        hl = l

li.sort(key=lambda x:x[0])

ans = 0
idx = 0
nowH = li[0][1]
for i in range(li[0][0], hl):
    if i == li[idx][0]:
        nowH = max(nowH, li[idx][1])
        idx += 1
    ans += nowH
idx = n-1
nowH = li[-1][1]
for i in range(li[-1][0], hl, -1):
    if i == li[idx][0]:
        nowH = max(nowH, li[idx][1])
        idx -=1
    ans += nowH
ans += hh
print(ans)