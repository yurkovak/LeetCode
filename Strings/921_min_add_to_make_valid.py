# O(N)
class Solution(object):
    def minAddToMakeValid(self, S):
        opened, closed = 0, 0
        
        for cur_p in S:
            if cur_p == '(': 
                opened += 1
            elif cur_p == ')' and opened > 0:
                opened -= 1
            else:
                closed += 1
        
        return opened + closed


if __name__ == '__main__':
    s = input("String with characters '(', ')', '{', '}': ")

    print('Minimum add to make parentheses valid: ', Solution().minAddToMakeValid(s))
