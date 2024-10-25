from bisect import bisect_right

n = int(input())
nums = []
for i in range(n):
    x = [int(x) for x in input().split()]
    nums.append(x)

nums.sort(key = lambda x: x[1])
# print(nums)
end_dates = [x[1] for x in nums]
dp = [0] * len(nums)
dp[0] = nums[0][2]
for i in range(1, n):
    s, e, p = nums[i]
    # rightmost index to insert s - 1 to keep list sorted
    left_index = bisect_right(end_dates, s - 1)
    if left_index == 0:
        dp[i] = max(p, dp[i-1])
    else:
        dp[i] = max(p + dp[left_index-1], dp[i-1])
    
print(dp[-1]) 
