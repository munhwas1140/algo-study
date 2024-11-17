import sys
input = sys.stdin.readline

paper = []
visited = [[0 for _ in range(10)] for _ in range(10)]
for _ in range(10):
    paper.append(list(map(int, input().split())))
d = {
    1: 0,
    2: 0,
    3: 0,
    4: 0,
    5: 0,
}
for k in range(5, 0, -1):
    tmp = [1 for _ in range(k)]
    tmp_visited = [0 for _ in range(k)]
    for j in range(11 - k):
        for i in range(11 - k):
            for t in range(j, j+k):
                comp = paper[t][i:i + k].copy()
                comp_visited = visited[t][i:i + k].copy()
                if comp != tmp or comp_visited != tmp_visited:
                    break
            else :
                d[k] += 1
                if d[k] > 5 :
                    print(-1)
                    exit()
                for t in range(j, j+k):
                    visited[t][i:i + k] = tmp

print(sum(d.values()))

# 0 0 0 0 0 0 0 0 0 0
# 0 0 1 1 1 1 1 1 0 0
# 0 0 1 1 1 1 1 1 0 0
# 0 0 1 1 1 1 1 1 0 0
# 0 0 1 1 1 1 1 1 0 0
# 0 0 1 1 1 1 1 1 0 0
# 0 0 1 1 1 1 1 1 0 0
# 0 0 0 0 0 0 0 0 0 0
# 0 0 0 0 0 0 0 0 0 0
# 0 0 0 0 0 0 0 0 0 0
# => 4