from collections import deque
n, k = map(int, input().split())

dq = deque([])
nums = [True for _ in range(100001)]
dq.append(n)
nums[n] = False

def find():
    ans = 0
    while True:
        l = len(dq)
        for _ in range(l):
            num = dq.popleft()
            if num == k:
                return ans

            if num + 1 <= 100000 and nums[num+1]:
                nums[num+1] = False
                dq.append(num+1)
            if num - 1 >= 0 and nums[num-1]:
                nums[num-1] = False
                dq.append(num-1)
            if num * 2 <= 100000 and nums[num*2]:
                nums[num*2] = False
                dq.append(num*2)
        ans += 1

print(find())
