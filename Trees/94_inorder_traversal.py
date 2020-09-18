from parse_input import *


class Solution:
    def inorderTraversal_DFS(self, root):
        if not root:
            return []
        
        return self.inorderTraversal_DFS(root.left) + [root.val] + self.inorderTraversal_DFS(root.right)


if __name__ == '__main__':
    line = input("A tree represented by a space separated list level after level (null for a missing nodes): ")

    root = string2tree(line)
    print("Inorder traversal: (by DFS)", Solution().inorderTraversal_DFS(root))