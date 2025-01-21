from collections import deque

st = ""
for i in range(3):
    st += ''.join(input().strip().split())

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

dq = deque([st])

visited = set()
visited.add(st)

def bfs():
    ans = 0
    while dq:
        l = len(dq)
        for _ in range(l):
            word = dq.popleft()
            if word == '123456780':
                return ans
            z = word.index('0')
            x = z//3
            y = z%3

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx < 0 or ny < 0 or nx >= 3 or ny >= 3: continue

                nz = nx*3 + ny

                li = list(word)
                li[nz], li[z] = li[z], li[nz]
                tmp = ''.join(li)
                if tmp in visited: continue
                dq.append(tmp)
                visited.add(tmp)
        ans += 1
    return -1

print(bfs())