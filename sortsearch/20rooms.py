# n = int(input())
# intervals = []
# events = []
# for i in range(n):
#     a,b = [int(x) for x in input().split()]
#     events.append([a,-1,i])
#     events.append([b,1,i])

# result = [0] * n
# ans = 0
# rooms = [1]
# events.sort()

# current = 0
# for s, e, index in events:
#     if e == -1:
#         current += 1
#         if len(rooms) == 0:
#             rooms.append(current)
#         result[index] = rooms[-1]
#         rooms.pop()
#     else:
#         rooms.append(result[index])
#         current -= 1
#     ans = max(ans, current)

# print(ans)
# for x in result:
#     print(x, end =" ")

import heapq

n = int(input())
intervals = []
for i in range(n):
    a,b = [int(x) for x in input().split()]
    intervals.append([a,b,i])

result = [0] * n
ans = 0
pq = []
intervals.sort()

for s, e, index in intervals:
    # print(pq)
    res = 0
    if len(pq) > 0 and s > pq[0][0]:
        x, room = heapq.heappop(pq)
        heapq.heappush(pq, [e, room])
        res = room
    else:
        ans += 1
        heapq.heappush(pq, [e, ans])
        res = ans
    result[index] = res

print(ans)
for x in result:
    print(x, end =" ")