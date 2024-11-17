def check():
    max_count = 0
    # 행 탐색
    for i in range(n):
        count = 1 # 다음 행으로 넘어갈 때 초기화
        for j in range(n - 1):
            if d[i][j] == d[i][j + 1]: # 같은 색이라면
                count += 1 # count 증가
            else: # 다른 색이라면
                count = 1 # count 초기화
            max_count = max(max_count, count) # 최대 개수 계산
    
    # 열 탐색
    for j in range(n):
        count = 1 # 다음 열로 넘어갈 때 초기화
        for i in range(n - 1):
            if d[i][j] == d[i + 1][j]: # 같은 색이라면
                count += 1 # count 증가
            else: # 다른 색이라면
                count = 1 # count 초기화
            max_count = max(max_count, count) # 최대 개수 계산    
    return max_count

import sys
input = sys.stdin.readline
n = int(input())
d = []
for i in range(n):
    d.append(list(input().rstrip()))

result = 1
for i in range(n):
    for j in range(n-1):
        # 오른쪽
        if j+1 < n:
            if d[i][j] != d[i][j+1]:
                d[i][j], d[i][j+1] = d[i][j+1], d[i][j]
                result = max(result, check())
                d[i][j], d[i][j+1] = d[i][j+1], d[i][j]
        # 아래
        if i+1 < n:
            if d[i][j] != d[i+1][j]:
                d[i][j], d[i+1][j] = d[i+1][j], d[i][j]
                result = max(result, check())
                d[i][j], d[i+1][j] = d[i+1][j], d[i][j]
print(result)
