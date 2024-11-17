import sys
input = sys.stdin.readline

n = int(input())
s = list(map(int, input().split()))
answer = [-1]*n
stack = []

for i in range(n):
    #print(s[i])
    while stack and s[i]>s[stack[-1]]: 
        answer[stack[-1]]=s[i] 
        stack.pop() 
    stack.append(i) 
    # print(stack)
    # print(answer)
print(*answer)