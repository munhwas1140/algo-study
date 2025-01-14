from collections import deque
n, k = map(int, input().split())
nums = input().split()

dq = deque([])
visited = set()
dq.append(nums)
visited.add(''.join(nums))
sortedNums = sorted(nums)
def bfs():
    cnt = 0
    while dq:
        l = len(dq)
        for _ in range(l):
            tmp = dq.popleft()
            if sortedNums == tmp:
                return cnt
            for i in range(n-k+1):
                tmp2 = tmp.copy()
                tmp2[i:i+k] = reversed(tmp2[i:i+k])
                strtmp = ''.join(tmp2)
                if strtmp not in visited:
                    visited.add(strtmp)
                    dq.append(tmp2)
        cnt += 1
    else:
        return -1

print(bfs())