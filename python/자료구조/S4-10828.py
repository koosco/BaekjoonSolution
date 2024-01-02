import sys
read = sys.stdin.readline

stk, res = [], []

for _ in range(int(read())):
    cmd = read().split()
    if cmd[0] == 'push':
        stk.append(str(cmd[1]))
    elif cmd[0] == 'pop':
        if stk:
            res.append(stk.pop())
        else:
            res.append('-1')
    elif cmd[0] == 'top':
        if stk:
            res.append(stk[-1])
        else:
            res.append('-1')
    elif cmd[0] == 'size':
        res.append(str(len(stk)))
    elif cmd[0] == 'empty':
        if stk:
            res.append('0')
        else:
            res.append('1')

print('\n'.join(res))