from bisect import bisect_left

n = int(input())
nums = [int(x) for x in input().split(" ")]

# print(n, nums)

st = []
for i in nums:
    if not st or st[-1] < i:
        st.append(i)
    else:
        index = bisect_left(st, i)
        st[index] = i

print(len(st))