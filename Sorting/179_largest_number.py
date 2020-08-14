from functools import cmp_to_key


class Solution(object):
    def largestNumber(self, nums):
        if len(nums) == 0:
            return ''
        
        nums_str = [str(n) for n in nums]
        nums_str = sorted(nums_str, key=cmp_to_key(lambda l, r: -1 if l + r > r + l else 0))
        
        res = ''.join(nums_str)
        res = '0' if res[0] == '0' else res
        
        return res


if __name__ == '__main__':
    nums = input('Space separated numbers: ')
    nums = [int(v) for v in nums.split(' ')]
    print('Largest number: ', Solution().largestNumber(nums))
