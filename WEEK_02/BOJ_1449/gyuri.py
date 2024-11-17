import sys
input = sys.stdin.readline
n, l = map(int, input().split())
s = list(map(int, input().split()))

s.sort() #오름차순 정렬
cnt = 1
start = s[0]

for i in s[1:]:
    if i < start + l: #시작점+테이프 사이에 들어오는지?
        continue
    else:
        start = i
        cnt += 1
print(cnt)
    