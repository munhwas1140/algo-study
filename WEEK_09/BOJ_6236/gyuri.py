def find_min_withdrawal(lt, rt, daily, n, m):
    if lt > rt:
        return lt
    
    mid = (lt + rt) // 2
    charge = mid
    num = 1
    
    for i in range(n):
        if charge < daily[i]:
            charge = mid
            num += 1
        charge -= daily[i]
    
    if num > m or mid < max(daily):
        return find_min_withdrawal(mid + 1, rt, daily, n, m)
    else:
        return find_min_withdrawal(lt, mid - 1, daily, n, m)

n, m = map(int, input().split())
daily = [int(input()) for _ in range(n)]
lt = min(daily)
rt = sum(daily)

# 재귀 호출로 최소 인출 금액을 찾음
result = find_min_withdrawal(lt, rt, daily, n, m)

print(result)
