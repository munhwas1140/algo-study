k = int(input())
T = int(input())
nums = [set() for _ in range(9)]
nums[1].add(k)
tmp = k
for i in range(2, 9):
    for j in range(1, (i//2)+1):
        for a in nums[j]:
            for b in nums[i-j]:
                nums[i].add(a + b)
                if a-b > 0:
                    nums[i].add(a - b)
                if b-a > 0:
                    nums[i].add(b - a)
                nums[i].add(a * b)
                nums[i].add(a // b)
                nums[i].add(b // a)
        if 0 in nums[i]:
            nums[i].remove(0)
    tmp = tmp*10 + k
    nums[i].add(tmp)

# for i in nums:
#     print(i)

for _ in range(T):
    n = int(input())
    for i in range(1, 9):
        if n in nums[i]:
            print(i)
            break
    else:
        print("NO")

# k
# k+k, k-k, k*k, k/k, kk
# k+k+k, k+k-k, k+k, k+k
# 1 1
# 2 11
# 3 21
# 4 31 22
# 5 41 23
# 6 51 42 33
# 7 61 52 43
# 8 71 62 53 44