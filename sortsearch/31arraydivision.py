from sys import stdin, stdout 
import heapq
from collections import defaultdict
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n, k = readintln()
nums = readintln()

# no subarray - circular greedy algo
# with subarray - binary search?

def check(mx):
    need = 1
    cur = 0
    for i in nums:
        if i >  mx:
            return False
        if i + cur > mx:
            need += 1
            cur = i
        else:
            cur = i + cur
    return need <= k

l = 0
r = sum(nums)

while(l <= r):
    m = (l + r)//2
    if check(m):
        r = m - 1
    else:
        l = m + 1
print(l)