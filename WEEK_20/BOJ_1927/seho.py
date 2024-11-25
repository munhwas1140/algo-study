import sys
import heapq
input = sys.stdin.readline

hq = []
n = int(input())
for _ in range(n):
    x = int(input())
    if x == 0:
        if len(hq) == 0:
            print(0)
        else:
            print(heapq.heappop(hq))
    else:
        heapq.heappush(hq, x)