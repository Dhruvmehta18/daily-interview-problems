# Hi, here's your problem today. This problem was recently asked by Uber:

# Given a list of numbers, find if there exists a pythagorean triplet in that list.
# A pythagorean triplet is 3 variables a, b, c where a^2 + b^2 = c^2

# Example:
# Input: [3, 5, 12, 5, 13]
# Output: True
# Here, 5^2 + 12^2 = 13^2.

def binarySearch(nums, low, high, k):
    while low<=high:
        mid = low + (high-low)//2
        if nums[mid]==k:
            return True
        elif nums[mid]<k:
            low = mid+1
        else:
            high = mid-1
    return False

def findPythagoreanTriplets(nums):
    sort_nums = sorted(nums)
    # 3, 5, 12, 13
    # 9, 25, 144, 169
    for i in range(len(sort_nums)-1, 1, -1):
        c = sort_nums[i]
        b1 = sort_nums[i-1]
        
        if b1*2<=c:
            return False
        
        if binarySearch(sort_nums, 0, i-2, (c**2 - b1**2)**0.5):
            return True
    
    return False
        

print(findPythagoreanTriplets([2, 12, 7, 13]))
# True
