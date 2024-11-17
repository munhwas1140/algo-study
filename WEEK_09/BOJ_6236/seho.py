import sys

input = sys.stdin.readline

n, m = map(int, input().split())

price = []
for _ in range(n):
    price.append(int(input()))

start = 1
end = sum(price)
ans = sys.maxsize

while start <= end:
    cnt = 1
    k = (end + start) // 2

    isPossible = True
    money = k
    for i in range(n):
        if price[i] > k :
            isPossible = False
            break
        if price[i] > money:
            cnt += 1
            money = k
        money -= price[i]

    if not isPossible or cnt > m:
        start = k+1
    else:
        ans = k
        end = k-1


print(ans)