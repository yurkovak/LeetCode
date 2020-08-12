# O(J + S)
class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        J_set = set(J)
        total = 0
        for s in S:
            if s in J_set:
                total += 1 
        return total


if __name__ == '__main__':
    J = input('J: ')
    S = input('S: ')
    print('Jewels in S: ', Solution().numJewelsInStones(J, S))