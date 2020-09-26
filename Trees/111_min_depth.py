from queue import Queue

from parse_input import *


class Solution(object):

    # DFS: O(N) time, O(logN) space
    def minDepth_DFS(self, root):
        if not root:
            return 0

        depth_left = self.minDepth_DFS(root.left)
        depth_right = self.minDepth_DFS(root.right)
        if depth_left > 0 and depth_right > 0:
            return 1 + min(depth_left, depth_right)
        else:
            return 1 + max(depth_left, depth_right)

    # BFS: O(N) time, O(N) space
    def minDepth_BFS(self, root):

        layer = Queue()
        if root:
            layer.put(root)

        count = 0
        while not layer.empty():
            count += 1
            for _ in range(layer.qsize()):
                cur_node = layer.get()
                if not cur_node.left and not cur_node.right:
                    return count
                if cur_node.left:
                    layer.put(cur_node.left)
                if cur_node.right:
                    layer.put(cur_node.right)

        return count


if __name__ == '__main__':
    line = input("A tree represented by a space separated list (null for a missing node): ")

    root = string2tree(line)
    print("Minimum depth: (by DFS)", Solution().minDepth_DFS(root))
    print("Minimum depth: (by BFS)", Solution().minDepth_BFS(root))