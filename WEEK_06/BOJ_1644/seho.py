n = int(input())

prime = [i for i in range(n+1)]

for i in range(2, n+1):
    for j in range(i*i, n+1, i):
        prime[j] = 0

prime = sorted(set(prime))[2:]
ans = 0
for i in range(len(prime)):
    num = 0
    for j in range(i, len(prime)):
        num += prime[j]
        if num == n :
            ans += 1
            break
        if num > n :
            break


print(ans)