n = int(input())
ranges = []
events = []
for i in range(n):
    x = [int(x) for x in input().split()]
    a = x[0]
    b = x[1]
    events.append([a, 1, i])
    events.append([b, -1, i])
    ranges.append(x)

contains = [0] * n
is_contained = [0] * n



# -----
#    -------
#      ----