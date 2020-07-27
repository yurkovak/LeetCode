# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# O(N)
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        current, i = head, n
        while i:
            current = current.next
            i -= 1
        if not current:
            return head.next
        
        p_d = head
        while current.next:
            current, p_d = current.next, p_d.next
        
        p_d.next = p_d.next.next
        return head