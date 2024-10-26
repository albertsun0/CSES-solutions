from sys import stdin, stdout 
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n,m  = readintln()
nums = readintln()

def two_sum(start, target):
    d = {}
    for i in range(start, n):
        cur = nums[i]
        need = target - cur
        if need in d:
            return d[need], i
        d[cur] = i
    return -1,-1

def sol():
    for i in range(n-2):
        # fix i
        target = m - nums[i]
        # two sum in rest of range
        a, b = two_sum(i+1, target)
        if a >= 0 and b >= 0:
            print(i+1, a+1, b+1)
            return
    print("IMPOSSIBLE")

sol()
