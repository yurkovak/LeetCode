# O(N)
class Solution(object):
    def canJump(self, nums):
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


if __name__ == '__main__':
    nums = input('Space separated array: ')
    nums = [int(v) for v in nums.split(' ')]
    print('Can jump: ', 'yes' if Solution().canJump(nums) else 'no')
