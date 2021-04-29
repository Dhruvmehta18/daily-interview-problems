# Hi, here's your problem today. This problem was recently asked by Facebook:

# Given a list of numbers, where every number shows up twice except for one number, find that one number.

# Example:
# Input: [4, 3, 2, 4, 1, 3, 2]
# Output: 1

# Challenge: Find a way to do this using O(1) memory.

def singleNumber(nums):
    ans = 0
    for x in nums:
        ans = ans ^ x
    return ans

print(singleNumber([4, 3, 2, 4, 1, 3, 2]))
# 1
