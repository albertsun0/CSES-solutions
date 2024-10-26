def readintln(): return [int(x) for x in input().split()]

n, target = readintln()
machines = readintln()

def check(time):
    products = 0
    for m in machines:
        products += time//m
    return products >= target

l = 0
r = 10000000000000000001

while(l <= r):
    # print(l,r)
    m = (l + r)//2
    works = check(m)
    if works:
        r = m - 1
    else:
        l = m + 1

print(l)
