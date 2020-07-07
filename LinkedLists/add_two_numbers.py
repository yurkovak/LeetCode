# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        l_res_tail = ListNode(None)
        l_res_head = l_res_tail
        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            cur_sum = v1 + v2 + carry
            new_digit = cur_sum % 10
            carry = 0 if cur_sum < 10 else 1
            
            l_res_tail.next = ListNode(new_digit)
            l_res_tail = l_res_tail.next
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
        
        return l_res_head.next