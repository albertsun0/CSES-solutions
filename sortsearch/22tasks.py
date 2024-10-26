def readintln(): return [int(x) for x in input().split()]
def readInt(): return int(input())

n = readInt()
tasks = []
for i in range(n):
    tasks.append(readintln())

tasks.sort()

curtime = 0
ans = 0

for t, d in tasks:
    curtime += t
    ans += d - curtime

print(ans)

# always choose tasks that finishes first (shortest time)

# intuitively, if you choose a long task first, that value will
# have a high negative impact on all other gains