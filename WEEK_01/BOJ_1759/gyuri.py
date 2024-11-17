import sys
input = sys.stdin.readline
m = ['a', 'e', 'i', 'o', 'u'] #모음
l, c = map(int, input().split())
words = input().split()
words.sort()
def check(arr):
    m_cnt, j_cnt = 0, 0

    for i in arr:
        if i in m:
            m_cnt += 1
        else:
            j_cnt += 1

    if m_cnt >= 1 and j_cnt >= 2:
        return True
    else:
        return False
    
def backtracking(arr):

    if len(arr) == l:
        if check(arr):
            print("".join(arr))
            return

    for i in range(len(arr), c):
        if arr[-1] < words[i]:
            arr.append(words[i])
            backtracking(arr)
            arr.pop()
for i in range(c - l + 1):
    a = [words[i]]
    backtracking(a)