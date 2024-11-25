import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

ans = nums[0]
for i in range(1, n):
    nums[i] = max(nums[i-1]+nums[i], nums[i])
print(max(nums))