import sys

input = sys.stdin.readline

def dfs(dic, num, ite):
    global ans_len
    global ans
    ch = num[ite]

    if not (dic.get(-1) is None): # 하나의 전화번호인지 확인
        ans = True
        return

    if dic.get(ch) is None:
        dic[ch] = {} # dictionary 안에 dictionary를 계속 넣어서 트리를 형성.
        # 하나의 전화번호가 끝에 도달했을 때 dictionary 안에 {-1 : True}를 넣어줌
        if ite == ans_len-1:
            dic[ch][-1] = True
        return

    ite += 1
    if ite >= len(num):
        return

    dfs(dic[ch], num, ite) # dictionary 안으로 계속 진입

t = int(input())

for _ in range(t):
    n = int(input())

    nums = []
    li = {}
    ans = False
    for _ in range(n):
        nums.append(input().rstrip())
    nums.sort()

    for num in nums:
        ans_len = len(num)

        for i in range(1, len(num)+1):
            dfs(li, num[:i], 0)
            if ans :
                break
        if ans:
            print("NO")
            break
    else : print("YES")
