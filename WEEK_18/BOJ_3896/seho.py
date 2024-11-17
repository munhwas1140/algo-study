import sys
input = sys.stdin.readline

T = int(input())

prime = [True for _ in range(1299709+1)]

for i in range(2, int(1299709**0.5)+1):
    if not prime[i]: continue
    for j in range(i+i, 1299709+1, i):
        prime[j] = False

for _ in range(T):
    n = int(input())
    s = n
    e = n
    if prime[n]:
        print(0)
    else:
        while True:
            if not prime[s]:
                s -= 1
            if not prime[e]:
                e += 1
            if prime[s] and prime[e]:
                break
        print(e-s)
