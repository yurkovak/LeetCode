from parse_input import *


# O(M + N)
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


if __name__ == '__main__':
    nums = input('Space separated values of l1: ').strip()
    l1 = str2List(nums)
    nums = input('Space separated values of l2: ').strip()
    l2 = str2List(nums)

    l_sum = Solution().addTwoNumbers(l1, l2)
    print('Sum: ', List2str(l_sum))


