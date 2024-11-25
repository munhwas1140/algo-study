# a^2 - b^2 = k
# (a+b) * (a-b) = k
# 8 7
# 49-36 = 13
# 36
# 49

n = int(input())
ans = []
base = 1
for i in range(1, int((n+1)**0.5)):
    if n%i == 0:
        if (n//i + i)%2 == 0:
            ans.append((n//i + i)//2)

if len(ans) != 0:
    ans.sort()
    for a in ans:
        print(a)
else:
    print(-1)