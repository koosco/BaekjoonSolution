import sys
read = sys.stdin.readline

read().rstrip()
n = set(map(int, read().split()))
read().rstrip()
m = list(map(int, read().split()))
res = []

for num in m:
    if num in n:
        res.append('1')
    else:
        res.append('0')

print('\n'.join(res))