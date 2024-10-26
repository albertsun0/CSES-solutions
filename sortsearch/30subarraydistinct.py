from sys import stdin, stdout 
from collections import defaultdict
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n, k = readintln()
nums = readintln()

d = defaultdict(int)
l = 0
ans = 0

for r in range(n):
    cur = nums[r]
    d[cur]+=1

    while(len(d) > k):
        left = nums[l]
        d[left] -= 1
        if d[left] == 0:
            del d[left]
        l += 1
    # on this iteration, we added new element to window at r
    # add all subarrays including this new r
    ans += (r - l + 1)
 
print(ans)