# O(N)
class Solution(object):
    def canJump(self, nums: List[int]) -> bool:
        if not nums: 
            return True
        
        maxReach = 0
        for i, el in enumerate(nums):
            if maxReach >= len(nums) - 1:
                return True
            if el == 0 and maxReach <= i:
                return False
            maxReach = max(maxReach, el + i)
        
        return True