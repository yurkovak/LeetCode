# O(N)
class Solution(object):
    def sortColors(self, nums) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        right_most = [-1, -1, -1]
        
        for i in range(len(nums)):
            if nums[i] == 0:
                nums[i], nums[right_most[0] + 1] = nums[right_most[0] + 1], nums[i]
                if nums[i] == 1:
                    nums[i], nums[right_most[1] + 1] = nums[right_most[1] + 1], nums[i]
                right_most[0] += 1
                right_most[1] += 1
                right_most[2] += 1
            elif nums[i] == 1:
                nums[i], nums[right_most[1] + 1] = nums[right_most[1] + 1], nums[i]
                right_most[1] += 1
                right_most[2] += 1
            else:
                right_most[2] += 1


if __name__ == '__main__':
    nums = input('Space separated colors: ')
    nums = [int(v) for v in nums.split(' ')]
    Solution().sortColors(nums)
    print('Sorted colors: ', nums)