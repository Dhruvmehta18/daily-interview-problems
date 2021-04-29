# Hi, here's your problem today. This problem was recently asked by Uber:

# Imagine you are building a compiler. Before running any code, the compiler must check that the parentheses in the program are balanced. Every opening bracket must have a corresponding closing bracket. We can approximate this using strings. 

# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 
# An input string is valid if:
# - Open brackets are closed by the same type of brackets.
# - Open brackets are closed in the correct order.
# - Note that an empty string is also considered valid.

# Example:
# Input: "((()))"
# Output: True

# Input: "[()]{}"
# Output: True

# Input: "({[)]"
# Output: False

class Solution:
    def isValid(self, s):
        stack = []
        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c)
            else:
                p = stack.pop()
                if not (c == ')' and p == '(' or c == '}' and p == '{' or c == ']' and p== '['):
                    return False
        
        if len(stack) == 0:
            return True
        else:
            return False

# Test Program
s = "()(){(())"
# should return False
print(Solution().isValid(s))

s = ""
# should return True
print(Solution().isValid(s))

s = "([{}])()"
# should return True
print(Solution().isValid(s))
