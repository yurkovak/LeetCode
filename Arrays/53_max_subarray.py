# O(N)
class Solution(object):
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return None
        
        prev = nums[0]
        max_sum = prev
        for i in range(1, len(nums)):
            curr_sum = prev + nums[i]
            prev = max(curr_sum, nums[i])
            max_sum = max(prev, max_sum)
            
        return max_sum