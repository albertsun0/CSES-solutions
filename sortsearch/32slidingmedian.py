from sys import stdin, stdout 
import heapq
from collections import defaultdict
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n, k = readintln()
nums = readintln()

# two heaps 
init = nums[:k]
init.sort()

left = [-x for x in init[: k//2]]
right = init[k//2:]

heapq.heapify(left)
heapq.heapify(right)

ans = []

def getMedian(left, right):
    

for i in range(k, n):
