
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def List2str(node):
    if not node:
        return ''

    vals = []
    while node:
        vals.append(str(node.val))
        node = node.next
    
    return ' '.join(vals)


def str2List(line):
    line = line.strip()
    if not line:
        return None

    l_head = ListNode(None)
    l_tail = l_head
    for v in line.split(' '):
        try:
            l_tail.next = ListNode(int(v))
        except ValueError as e:
            raise ValueError('Wrong input formatting, separate nodes values by one space')
        l_tail = l_tail.next
    return l_head.next


__all__ = ['ListNode', 'List2str', 'str2List']