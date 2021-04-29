# Hi, here's your problem today. This problem was recently asked by Twitter:

# You are given the root of a binary tree. Invert the binary tree in place. That is, all left children should become right children, and all right children should become left children.

# Example:

#     a
#    / \
#   b   c
#  / \  /
# d   e f

# The inverted version of this tree is as follows:

#   a
#  / \
#  c  b
#  \  / \
#   f e  d


class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

    def preorder(self):
        print(self.value,end=" ")
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()
    
    def _swapLeftRight(self):
        if self is not None:
            temp = self.left
            self.left = self.right
            self.right = temp
            
    def _isBothChildNone(self) -> bool:
        return self.left is None and self.right is None
    
    def _invertHelper(self):
        if self._isBothChildNone():
            return
        invert(self.left)
        invert(self.right)
        self._swapLeftRight()

def invert(node):
    if node is None:
        return
    node._invertHelper()


root = Node('a')
root.left = Node('b')
root.right = Node('c')
root.left.left = Node('d')
root.left.right = Node('e')
root.right.left = Node('f')

root.preorder()
# a b d e c f
print(end="\n")
invert(root)
root.preorder()
# a c f b e d
