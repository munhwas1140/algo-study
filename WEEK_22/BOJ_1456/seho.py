a, b = map(int, input().split())

prime = [True for _ in range(int(b**0.5)+1)]
cnt = 0
for i in range(2, int(b**0.5)+1):
    if prime[i]:
        for j in range(i*i, int(b**0.5)+1, i):
            prime[j] = False

for i in range(2, len(prime)):
    if prime[i]:
        p = i*i
        while p <= b:
            if p >= a:
                cnt += 1
            if p > b // i:
                break
            p *= i
print(cnt)

# 9 49
# 16 32 9 27 25 49