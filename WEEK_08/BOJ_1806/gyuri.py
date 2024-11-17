import sys
n, s = map(int, input().strip().split())
nums = list(map(int, input().strip().split()))

left, right = 0,0
sum = 0
min_length=sys.maxsize

while True:
    if sum >= s: #현재 부분의 배열의 합이 s이상이면
        min_length=min(min_length,right-left) # 더 짧은 거 선택
        sum -= nums[left] #left를 오른쪽으로 이동시키고 sum 업데이트
        left +=1
    elif right == n: #right가 배열의 끝에 도달하면 반복문 종료
        break
    else:
        sum += nums[right] #sum 업데이트
        right+=1
        
#초기값 그대로면, 합이 s 이상이 되는 부분 배열을 찾지 못했다는 의미이므로 0을 출력
if min_length == sys.maxsize: 
    print(0)
else:
    print(min_length)