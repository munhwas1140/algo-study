import sys
from collections import defaultdict
input = sys.stdin.readline

T = int(input())

def find(x):
    if x == parent[x]: return parent[x]

    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)


    if a < b:
        parent[b] = a
        freq[a] += freq[b]
    else:
        parent[a] = b
        freq[b] += freq[a]

for _ in range(T):
    parent = []
    name = dict()
    freq = dict()
    n = int(input())
    num = -1
    for _ in range(n):
        a, b = input().split()
        if a not in name:
            num += 1
            name[a] = num
            parent.append(num)
            freq[num] = 1

        if b not in name:
            num += 1
            name[b] = num
            parent.append(num)
            freq[num] = 1

        x = name[a]
        y = name[b]

        if find(x) != find(y):
            union(x, y)
        print(freq[find(x)])



