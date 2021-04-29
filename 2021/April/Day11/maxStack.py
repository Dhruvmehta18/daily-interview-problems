# Hi, here's your problem today. This problem was recently asked by Twitter:

# Implement a class for a stack that supports all the regular functions (push, pop) and an additional function of max()
# which returns the maximum element in the stack (return None if the stack is empty).
# Each method should run in constant time.


class MaxStack:
    def __init__(self):
      self._top = -1
      self._maxStack = []
      self._stack = []

    def push(self, val):
        self._stack.append(val)
        if self._top == -1:
            self._maxStack.append(val)
        else:
            max_num = max(self._maxStack[self._top], val)
            self._maxStack.append(max_num)
        self._top += 1

    def pop(self):
        self._stack.pop()
        self._maxStack.pop()
        self._top -= 1

    def max(self):
        if self._top == -1:
            return None
        else:
            return self._maxStack[self._top]


s = MaxStack()
s.push(1)
s.push(2)
s.push(3)
s.push(2)
print(s.max())
# 3
s.pop()
s.pop()
print(s.max())
# 2
