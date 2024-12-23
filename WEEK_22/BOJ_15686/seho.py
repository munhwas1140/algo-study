import sys
input = sys.stdin.readline

n, m = map(int, input().split())
house = []
chick = []

for i in range(n):
    tmp = input().split()
    for j in range(n):
        if tmp[j] == '1':
            house.append((i, j))
        elif tmp[j] == '2':
            chick.append((i, j))

selectedChicken = []
ans = sys.maxsize
def back(s):
    global ans

    if len(selectedChicken) == m:
        dist = 0
        for hi, hj in house:
            minDist = sys.maxsize
            for ci, cj in selectedChicken:
                minDist = min(minDist, abs(ci-hi)+abs(cj-hj))
            dist += minDist
        selectedChicken.pop()
        return dist

    for i in range(s+1, len(chick)):
        selectedChicken.append(chick[i])
        ans = min(ans, back(i))
    if len(selectedChicken):
        selectedChicken.pop()
    return ans

print(back(-1))