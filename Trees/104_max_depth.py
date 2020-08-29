from queue import Queue

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


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
            for i in range(layer.qsize()):
                cur_node = layer.get()
                if cur_node.left:
                    layer.put(cur_node.left)
                if cur_node.right:
                    layer.put(cur_node.right)
        
        return count 


def check_node(node, n_val):
    if not node:
        raise RuntimeError('The provided list is incorrect, no parent node for ' + n_val)
    

def string2tree(line):
    node_vals = Queue()
    for v in line.split(' '):
        node_vals.put(v)

    n_val = node_vals.get()
    if n_val and n_val != 'null':
        root = TreeNode(int(n_val))
    else:
        return None
    
    level = Queue()
    level.put(root)
    while node_vals.qsize():
        for _ in range(level.qsize()):
            cur_node = level.get()
            
            n_val = node_vals.get()
            if n_val != 'null':
                check_node(cur_node, n_val)
                new_node = TreeNode(int(n_val))
                cur_node.left = new_node
                level.put(new_node)
            else:
                level.put(None)

            n_val = node_vals.get()
            if n_val != 'null':
                check_node(cur_node, n_val)
                new_node = TreeNode(int(n_val))
                cur_node.right = new_node
                level.put(new_node)
            else:
                level.put(None)
    
    return root


if __name__ == '__main__':
    line = input("A tree represented by a space separated list (null for a missing node): ")

    root = string2tree(line)
    print("Maximum depth: (by DFS)", Solution().maxDepth_DFS(root))
    print("Maximum depth: (by BFS)", Solution().maxDepth_BFS(root))