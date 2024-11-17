import sys
input = sys.stdin.readline

s = list(input().strip())  
op = ["+", "-", "*", "/", "(", ")"] 

stack = []
result = []

for i in s:
    if i.isalpha():
        result.append(i)
    elif i == "(":
        stack.append(i)
    elif i == ")":
        while stack and stack[-1] != "(":
            result.append(stack.pop())
        stack.pop()  # '(' 제거
    else:
        while stack and stack[-1] != '(' and op.index(stack[-1]) // 2 >= op.index(i) // 2:
            result.append(stack.pop())
        stack.append(i)

while stack:
    result.append(stack.pop())

print(''.join(result)) #list->str
