from collections import deque

from parse_input import *


# O(N)
class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
        res = []

        level_queue = deque()
        level_queue.append(root)
        while len(level_queue):
            level_size = len(level_queue)
            level = []
            for _ in range(level_size):
                cur_node = level_queue.popleft()
                level.append(cur_node.val)
                if cur_node.left:
                    level_queue.append(cur_node.left)
                if cur_node.right:
                    level_queue.append(cur_node.right)

            res.append(level)

        return res


if __name__ == '__main__':
    line = input('A tree represented by a space separated list level after level (null for a missing nodes): ')

    root = string2tree(line)
    level_order = Solution().levelOrder(root)

    print('Level order traversal: ')
    for level in level_order:
        print(level)