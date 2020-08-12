# O(N)
class Solution(object):
    def maxSubArray(self, nums):
        if not nums:
            return None
        
        prev = nums[0]
        max_sum = prev
        for i in range(1, len(nums)):
            curr_sum = prev + nums[i]
            prev = max(curr_sum, nums[i])
            max_sum = max(prev, max_sum)
            
        return max_sum


if __name__ == '__main__':
    nums = input('Space separated array: ')
    nums = [int(v) for v in nums.split(' ')]
    print('Maximum subarray sum: ', Solution().maxSubArray(nums))
