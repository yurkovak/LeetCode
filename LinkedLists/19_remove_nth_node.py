from parse_input import *


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


if __name__ == '__main__':
    nums = input('Space separated values of l: ').strip()
    l = str2List(nums)
    n = int(input('N: '))

    l_sum = Solution().removeNthFromEnd(l, n)
    print('After removal: ', List2str(l_sum))

