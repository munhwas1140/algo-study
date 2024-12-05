n = int(input())
prime = [i for i in range(n+1)]

for i in range(2, int(n**0.5)+1):
    if prime[i] != 0:
        for j in range(i*i, n+1, i):
            prime[j] = 0
prime = set(prime[2:])
prime.remove(0)


ans = set() # 상근수를 계산하는 과정에서 나온 값들을 저장할 리스트
for num in prime:
    tmp = set()
    tmp.add(num)
    while True:
        # 각 자리수의 제곱의 합이 ans안에 있으면 더이상 계산할 필요x
        if num in ans:
            ans = ans | tmp
            break

        # 각 자리수의 제곱을 계산
        li = list(str(num))
        squareSum = 0
        for sn in li:
            squareSum += int(sn)**2

        # 만약 각 자리수의 제곱이 계속 반복된다면 break
        if squareSum in tmp:
            break

        # 상근수일 때 계산한 과정에서 나온 값들을 ans에 저장
        if squareSum == 1:
            ans = ans | tmp
            break
        else:
            tmp.add(squareSum)

        num = squareSum

ans = sorted(list(ans))
for a in ans:
    if a in prime:
        print(a)