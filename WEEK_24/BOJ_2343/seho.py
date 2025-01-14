import sys
input = sys.stdin.readline

n, m = map(int, input().split())

nums = list(map(int, input().split()))
start = max(nums)
end = sum(nums)


while end >= start:
    cnt = 0
    num = 0
    mid = (start + end) // 2
    for i in range(n):
        num += nums[i]
        if num > mid:
            cnt += 1
            num = nums[i]

    if num <= mid:
        cnt += 1

    if cnt > m:
        start = mid+1
    else :
        end = mid-1

print(start)