from sys import stdin, stdout 
from collections import defaultdict
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n, target= readintln()
nums = readintln()

d = defaultdict(int)
d[0] = 1
prefix = 0
ans = 0
for i in nums:
    prefix += i
    # need prefixi - prefixj = target
    # look for prefixj = prefixi - target
    need = prefix - target
    if need in d:
        ans += d[need]

    d[prefix] += 1

print(ans)