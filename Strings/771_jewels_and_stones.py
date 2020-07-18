# O(J + S)
class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        J_set = set(J)
        return len(filter(lambda x: x in J_set, S))
        