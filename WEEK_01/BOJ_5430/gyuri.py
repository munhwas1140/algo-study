from collections import deque
import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    p = input().rstrip() 
    n = int(input())  
    arr = input().rstrip()[1:-1] 

    if arr:
        arr = deque(arr.split(","))
    else:
        arr = deque()
    reverse = False 
    error = False 

    for cmd in p:
        if cmd == 'R':
            reverse = not reverse
        elif cmd == 'D':
            if arr:
                if reverse: # 홀수 일 때 뒤에서 뽑기. 아예 뒤집지 않음.
                    arr.pop()
                else:
                    arr.popleft()
            else:
                error = True
                break
    if error:
        print("error")
    else:
        if reverse:
            arr.reverse()  # 최종적으로 뒤집힌 상태면 뒤집어 줌
        print("[" + ",".join(arr) + "]")