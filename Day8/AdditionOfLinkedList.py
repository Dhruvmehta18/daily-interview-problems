# Hi, here's your problem today. This problem was recently asked by Microsoft:

# You are given two linked-lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

# Example:
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x: int):
        self.val = x
        self.next = None
        
    def __add__(self, x) -> int:
        return self.val + x.val

class Solution:
    def addTwoNumbers(self, l1, l2, c:int = 0):
        if l1 is None and l2 is None:
            if c>0:
                return ListNode(c)
            else:
                return None
        elif l1 is None:
            i = l2.data + c
            digitNode = ListNode(i%10)
            digitNode.next = self.addTwoNumbers(None, l2.next,int(i/10))
            return 
        elif l2 is None:
            i = l1.data + c
            digitNode = ListNode(i%10)
            digitNode.next = self.addTwoNumbers(l1.next, None, int(i/10))
        else:
            i = l1 + l2 + c
            digitNode = ListNode(i%10)
            digitNode.next = self.addTwoNumbers(l1.next, l2.next, int(i/10))
            return digitNode

l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

result = Solution().addTwoNumbers(l1, l2)
while result:
    if result.next is not None:
        print(result.val, end="->")
    else:
        print(result.val, end="\n")
    result = result.next
# 7 0 8
