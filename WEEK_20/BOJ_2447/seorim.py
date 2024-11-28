import sys

def dac(n):
    if n == 3:
        return ["***", "* *", "***"]
    
    div = n//3
    pattern = dac(div)
    
    top_bottom = [line * 3 for line in pattern]
    middle = [line + " " * div + line for line in pattern]
        
    return top_bottom + middle + top_bottom
  
n = int(sys.stdin.readline())  
star = dac(n)
for line in star:
    print(line)