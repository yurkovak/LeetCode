from collections import deque


class Solution:
    def isValid(self, s):
        pair_p = {'(': ')', '{': '}', '[': ']'}
        open_p = deque()
        
        for cur_p in s:
            if cur_p == '(' or cur_p == '{' or cur_p == '[':
                open_p.append(cur_p)
            elif len(open_p) and cur_p == pair_p[open_p[-1]]:
                open_p.pop()
            else:
                return False
        
        return len(open_p) == 0


if __name__ == '__main__':
    print("String with characters '(', ')', '{', '}': ")
    s = input()

    print('Is valid:', Solution().isValid(s))
