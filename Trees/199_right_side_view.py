from collections import deque

from parse_input import *


# O(N)
class Solution(object):
    def rightSideView(self, root):
        result = []

        right_side = deque()
        right_side.append((root, 0))
        max_depth = 0
        while len(right_side):
            cur_node, cur_depth = right_side.pop()

            while cur_node:
                cur_depth += 1
                if cur_depth > max_depth:
                    result.append(cur_node.val)
                    max_depth += 1
                if cur_node.left:
                    right_side.append((cur_node.left, cur_depth))

                cur_node = cur_node.right

        return result


if __name__ == '__main__':
    line = input("A tree represented by a space separated list level after level (null for a missing nodes): ")

    root = string2tree(line)
    print("Right side view:: ", Solution().rightSideView(root))