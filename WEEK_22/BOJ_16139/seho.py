import sys
from collections import defaultdict
input = sys.stdin.readline

s = input().strip()
n = int(input())
c = [[0 for _ in range(123-97)] for _ in range(len(s)+1)]

for i in range(1, len(s)+1):
    c[i] = c[i-1].copy()
    ch = ord(s[i-1])-97
    c[i][ch] += 1

for _ in range(n):
    a, l, r = input().split()

    print(c[int(r)+1][ord(a)-97] - c[int(l)][ord(a)-97])
