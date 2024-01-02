import sys
read = sys.stdin.readline

stk = []

for _ in range(int(read())):
    num = int(read())
    if num == 0:
        stk.pop()
    else:
        stk.append(num)

print(sum(stk))