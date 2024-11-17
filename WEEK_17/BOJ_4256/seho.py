import sys
input = sys.stdin.readline

T = int(input())

def dfs(preo, ino):
    if not preo:
        return []
    root = preo[0]
    rootIdx = ino.index(root)

    left = dfs(preo[1:1+rootIdx], ino[:rootIdx])
    right = dfs(preo[1 + rootIdx:], ino[rootIdx + 1:])

    return left + right + [root]

for _ in range(T):
    n = int(input())
    preo = list(map(int, input().split()))
    ino = list(map(int, input().split()))

    print(*dfs(preo, ino))




# pre : root a b c ...
# in  : leftSubTree root rightSubtree
# post: subTree root

# 6 5 4 8
# 5 6 8 4
#       6
# 5 8 4 6
#