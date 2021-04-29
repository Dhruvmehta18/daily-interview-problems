# Hi, here's your problem today. This problem was recently asked by Microsoft:

# Given a string, find the length of the longest substring without repeating characters.

# Can you find a solution in linear time

class Solution:
    def lengthOfLongestSubstring(self, s):
        first,last,m = 0,0,0
        for i in range(len(s) - 1):
            if s[i]==s[i+1]:
                last = i+1
                m = max(last - first, m)
                first = i+1
                last = i+1
        
        m = max(len(s) - first, m)
        return m

print(Solution().lengthOfLongestSubstring('abbcdeffghijkk'))
# 10
