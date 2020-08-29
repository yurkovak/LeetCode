from parse_input import *


# O(N + M)
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




if __name__ == '__main__':
    nums = input('Space separated values of l1: ').strip()
    l1 = str2List(nums)
    nums = input('Space separated values of l2: ').strip()
    l2 = str2List(nums)

    l_res = Solution().mergeTwoLists(l1, l2)
    print('Sorted: ', List2str(l_res))
