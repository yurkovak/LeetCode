from queue import Queue


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def check_node(node, n_val):
    if not node:
        raise RuntimeError('The provided list is incorrect, no parent node for ' + n_val)
    

def string2tree(line):
    node_vals = Queue()
    for v in line.split(' '):
        node_vals.put(v)

    n_val = node_vals.get() if not node_vals.empty() else 'null'
    if n_val and n_val != 'null':
        root = TreeNode(int(n_val))
    else:
        return None

    # fill in level by level in order: left -> right, left -> right
    level = Queue()
    level.put(root)
    left = True
    while not node_vals.empty():
        if left:
            if not level.empty():
                cur_node = level.get()
            else:
                cur_node = None

        n_val = node_vals.get()
        if n_val != 'null':
            check_node(cur_node, n_val)
            new_node = TreeNode(int(n_val))
            if left:
                cur_node.left = new_node
            else:
                cur_node.right = new_node
            level.put(new_node)

        left = not left
    
    return root


__all__ = ['TreeNode', 'string2tree']