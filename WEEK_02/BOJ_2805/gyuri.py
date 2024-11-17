import sys
input = sys.stdin.readline

n, m = map(int, input().split())
data = list(map(int, input().split()))
data.sort()

def cut(data, l, h):
    while l <= h:
        mid = (l + h) // 2
        sum = 0
        for val in data:
            if val > mid:
                sum += val - mid
        
        if sum >= m:
            l = mid + 1
        else:
            h = mid - 1
    return h

result = cut(data, 1, data[-1])
print(result)
