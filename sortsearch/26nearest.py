from sys import stdin, stdout 
def readintln(): return [int(x) for x in stdin.readline().split()]
def readInt(): return int(stdin.readline())

n = readintln()
nums = readintln()

st = []
res = []
for i,n in enumerate(nums):
    while(st and st[-1][0] >= n):
        st.pop()
    if len(st) == 0:
        res.append(0)
    else:
        res.append(st[-1][1] + 1)
    st.append((n,i))

for x in res:
    print(x, end=" ")

# standard monotomic stack
# keep sorted stack of prev values

# 2 5 1 4 8 3 2 5

# 2
# 2 5
# 1
# 1 4 
# 1 4 8
# 1 3