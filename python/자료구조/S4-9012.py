import sys
read = sys.stdin.readline

def sol():
    parenthesis = read().rstrip()
    ret = 0
    
    for s in parenthesis:
        if s == '(':
            ret += 1
        elif s == ')':
            ret -= 1
        
        if ret < 0:
            return False
    
    if ret == 0:
        return True
    else:
        return False

res = []

for _ in range(int(read())):
    if sol():
        res.append('YES')
    else:
        res.append('NO')

print('\n'.join(res))