# Hi, here's your problem today. This problem was recently asked by Google:

# Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time.

# Example 1:
# Input: [3, 3, 2, 1, 3, 2, 1]
# Output: [1, 1, 2, 2, 3, 3, 3]

# Challenge: Try sorting the list using constant space

def sortNums(nums: list) -> list:
    numsL = [0,0,0]
    ans = []
    for i in nums:
        numsL[i-1] += 1
    
    for i in range(3):
        ans.extend([i+1 for j in range(numsL[i])])
    return ans
    

print(sortNums([3, 3, 2, 1, 3, 2, 1]))
# [1, 1, 2, 2, 3, 3, 3]
