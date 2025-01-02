import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
m = int(input())

if sum(nums) < m:
    print(max(nums))
else:
    start = 0
    end = max(nums)

    while end >= start:

        mid = (end+start) // 2
        budget = 0
        for i in range(n):
            if mid < nums[i]:
                budget += mid
            else:
                budget += nums[i]

        if budget <= m:
            start = mid+1
        else:
            end = mid-1
    print(end)