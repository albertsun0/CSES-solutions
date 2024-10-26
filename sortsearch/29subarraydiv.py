from sys import stdin, stdout 
from collections import defaultdict
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n = readInt()
nums = readintln()

d = defaultdict(int)
d[0] = 1
prefix = 0
ans = 0
for i in nums:
    prefix += i
    # need (prefixi - prefixj) % n = 0
    # prefixi % n == prefixj % n 
    # 
    need = prefix % n
    if need in d:
        ans += d[need]

    d[prefix % n] += 1

print(ans)