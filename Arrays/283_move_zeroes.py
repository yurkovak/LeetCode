# O(N)
class Solution(object):
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        frst_zero = -1
        
        for i in range(len(nums)):
            if nums[i] == 0 and frst_zero == -1:
                frst_zero = i
            elif nums[i] != 0 and frst_zero != -1:
                nums[i], nums[frst_zero] = nums[frst_zero], nums[i]
                frst_zero += 1
                


if __name__ == '__main__':
    nums = input('Space separated array: ')
    nums = [int(v) for v in nums.split(' ')]
    Solution().moveZeroes(nums)
    print('Zeros moved: ', nums)