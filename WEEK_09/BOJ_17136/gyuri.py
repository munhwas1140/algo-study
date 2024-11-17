#색종이를 붙일 수 있는지
#(a1, b1)에서 (a2, b2)까지 모두 1인지 확인
def promise(a1, a2, b1, b2): 
    for i in range(a1, a2+1):
        for j in range(b1, b2+1):
            if not paper[i][j]:
                return False #아니면
    return True #범위가 1로 가득 차 있으면

def attach(a1, a2, b1, b2, w): # 색종이 붙이기(1)/떼기(0)
    for i in range(a1, a2+1):
        for j in range(b1, b2+1):
            paper[i][j] = w

def glue(p):
    global result
    for y in range(10):
        for x in range(10):
            if paper[y][x]:
                for c in range(5):
                    ny, nx = y + c, x + c
                    if confetti[c] and ny < 10 and nx < 10 : # 색종이가 남았고 범위안에 있으면
                        if promise(y, ny, x, nx): #붙일 수 있는 지 확인 
                            attach(y, ny, x, nx, 0)
                            confetti[c] -= 1
                            glue(p+1) #백트래킹. 재귀적으로 호출.
                            confetti[c] += 1
                            attach(y, ny, x, nx, 1)
                return
    result = min(result, p) #최솟값 갱신

import sys
#입력받은 종이판
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(10)]

confetti = [5, 5, 5, 5, 5] #색종이의 개수
result = 26 #최대 색종이 개수
glue(0)

if result == 26: #해결할 수 없었던 경우
    print(-1)
else:
    print(result)