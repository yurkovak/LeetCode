from collections import deque

from parse_input import *


class Solution:
    def inorderTraversal_rec(self, root):
        if not root:
            return []
        
        return self.inorderTraversal_rec(root.left) + [root.val] + self.inorderTraversal_rec(root.right)

    def inorderTraversal_iter(self, root):
        if not root:
            return []

        inorder = []
        stack = deque()
        stack.append(root)
        down = True
        while stack:
            cur_node = stack[-1]
            if cur_node.left and down:
                stack.append(cur_node.left)
            else:
                inorder.append(cur_node.val)
                stack.pop()
                down = False
                if cur_node.right:
                    stack.append(cur_node.right)
                    down = True

        return inorder

if __name__ == '__main__':
    line = input("A tree represented by a space separated list level after level (null for a missing nodes): ")

    root = string2tree(line)
    print("Inorder traversal: (by recursion)", Solution().inorderTraversal_rec(root))
    print("Inorder traversal: (by iteration)", Solution().inorderTraversal_iter(root))