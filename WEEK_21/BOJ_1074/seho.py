n, r, c = map(int, input().split())

ans = 0

def daq(n, r, c):
    global ans
    n //= 2
    if n == 1:
        ans += 2*r + c
        return

    if r < n and c < n:
        daq(n, r, c)
    elif r < n and c >= n:
        ans += (n**2)
        daq(n, r, c-n)
    elif r >= n and c < n:
        ans += 2*(n**2)
        daq(n, r-n, c)
    else:
        ans += 3*(n**2)
        daq(n, r-n, c-n)

daq(2**n ,r, c)
print(ans)

# 0,0 / 0,1 / 1,0 / 1,1