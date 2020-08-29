from queue import Queue

from parse_input import *


class Solution(object):

    # DFS: O(N) time, O(logN) space
    def maxDepth_DFS(self, root):
        if not root:
            return 0
        
        return 1 + max(self.maxDepth_DFS(root.left), self.maxDepth_DFS(root.right))

    # BFS: O(N) time, O(N) space
    def maxDepth_BFS(self, root):
        
        layer = Queue()
        if root:
            layer.put(root)
        
        count = 0
        while not layer.empty():
            count += 1
            for _ in range(layer.qsize()):
                cur_node = layer.get()
                if cur_node.left:
                    layer.put(cur_node.left)
                if cur_node.right:
                    layer.put(cur_node.right)
        
        return count 


if __name__ == '__main__':
    line = input("A tree represented by a space separated list (null for a missing node): ")

    root = string2tree(line)
    print("Maximum depth: (by DFS)", Solution().maxDepth_DFS(root))
    print("Maximum depth: (by BFS)", Solution().maxDepth_BFS(root))