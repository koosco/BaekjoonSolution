from queue import deque
import sys
read = sys.stdin.readline

q = deque()
res = []

for _ in range(int(read())):
    cmd = read().split()
    if cmd[0] == 'push_front':
        q.appendleft(str(cmd[1]))
    elif cmd[0] == 'push_back':
        q.append(str(cmd[1]))
    elif cmd[0] == 'pop_front':
        if q:
            res.append(q.popleft())
        else:
            res.append('-1')
    elif cmd[0] == 'pop_back':
        if q:
            res.append(q.pop())
        else:
            res.append('-1')
    elif cmd[0] == 'size':
        res.append(str(len(q)))
    elif cmd[0] == 'empty':
        if q:
            res.append('0')
        else:
            res.append('1')
    elif cmd[0] == 'front':
        if q:
            res.append(q[0])
        else:
            res.append('-1')
    elif cmd[0] == 'back':
        if q:
            res.append(q[-1])
        else:
            res.append('-1')

print('\n'.join(res))