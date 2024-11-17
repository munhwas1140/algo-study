import sys
input = sys.stdin.readline

n = int(input())
tree = [[] for _ in range(n)]
li = list(map(int, input().split()))
dnode = int(input())
def dfs(node):
    if len(tree[node]) == 0:
        tree[node].append(-1)
        return
    for nextNode in tree[node]:
        dfs(nextNode)

for i in range(n):
    if li[i] == -1:
        continue
    else:
        tree[li[i]].append(i)
ans = 0
if li[dnode] != -1:
    tree[li[dnode]].remove(dnode)
dfs(dnode)
for i in range(n):
    if len(tree[i]) == 0:
        ans += 1
print(ans)