import sys
import heapq

input = sys.stdin.readline

heap = []
n = int(input())
for _ in range(n):
    data = int(input())
    if data == 0:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, data)