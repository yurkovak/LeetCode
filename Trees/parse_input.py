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

    n_val = node_vals.get()
    if n_val and n_val != 'null':
        root = TreeNode(int(n_val))
    else:
        return None
    
    level = Queue()
    level.put(root)
    while node_vals.qsize():
        new_level_size = level.qsize()
        for _ in range(new_level_size):
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


__all__ = ['TreeNode', 'string2tree']