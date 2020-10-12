from parse_input import *


# O(N)
class Solution:
    def reverseList(self, head):
        prev = None
        curr = head

        while curr:
            nxt = curr.next
            curr.next = prev

            prev = curr
            curr = nxt

        return prev


if __name__ == '__main__':
    nums = input('Space separated values of l: ').strip()
    l = str2List(nums)

    l_sum = Solution().reverseList(l)
    print('Reversed: ', List2str(l_sum))