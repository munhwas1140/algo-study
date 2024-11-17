import sys
input = sys.stdin.readline()

n, m = map(int, input.split())

if n % 2 != 0 and m % 2 != 0 :
    print("B")
else :
    print("A")

# B가 이기는 조건 :
# 1 3 / 3 3 /

# 3
# 1 2 A
# 1 1 B

# 4
# 1 3 / 2 2 A
# 2 1 / 1 1 B
# 1 1       A

# 5
# 1 4  A
# 1 3  B
# 1 2  A
# 1 1  B

# 6
# 1 5 / 3 3 A
# 1 4 B
# 1 3 A
# 1 2 B
# 1 1 A

# 7
# 1 6 / 3 4 A
# 1 5 / 3 3 / 1 3 B
# 1 4 A
# 1 3 B
# 1 2 A
# 1 1 B

# 짝수 : A
# 홀수 : B
