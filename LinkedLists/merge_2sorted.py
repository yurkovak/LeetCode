# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        lnew_head = ListNode(0)
        lnew_tail = lnew_head
        
        while l1 and l2: 
            if l1.val < l2.val:
                lnew_tail.next = l1
                l1, lnew_tail = l1.next, lnew_tail.next
            else:
                lnew_tail.next = l2
                l2, lnew_tail  = l2.next, lnew_tail.next
        
        lnew_tail.next = l1 if l1 else l2
        return lnew_head.next