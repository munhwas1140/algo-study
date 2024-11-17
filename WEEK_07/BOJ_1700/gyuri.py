import sys
input = sys.stdin.readline
n, k = map(int, input().split())
data = list(map(int, input().split()))

tap = []
answer = 0

for i in range(k):
    if data[i] in tap:
        continue
    if len(tap) < n:
        tap.append(data[i])
        continue
    tmp = []
    for c in tap: # 꽂혀져 있는 코드를
        if c in data[i:]: # 또 이용하는지?
            tmp.append(data[i:].index(c))
        else:
            tmp.append(101)
    target = tmp.index(max(tmp))
    tap.remove(tap[target])
    tap.append(data[i])
    answer += 1

print(answer)