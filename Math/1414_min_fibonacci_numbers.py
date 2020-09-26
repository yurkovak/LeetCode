
# O(logk)
class Solution:
    def findMinFibonacciNumbers(self, k):
        if k <= 1:
            return k

        # iterate right before the closest fib num to k is found
        prev_prev, prev = 0, 1
        while prev <= k:
            prev_prev, prev = prev, prev_prev
            prev += prev_prev

        # iterate down and collect k as a sum of fib nums
        n_nums, residual = 0, k
        while residual > 0:
            if residual - prev >= 0:
                residual -= prev
                n_nums += 1
            if residual == 1:
                return n_nums + 1

            prev_prev, prev = prev, prev_prev
            prev_prev -= prev

        return n_nums


if __name__ == '__main__':
    k = int(input('k = '))
    assert k >= 0, 'Provide a valid number'
    
    print('Minimum number of Fibonacci numbers to sum into k: ', Solution().findMinFibonacciNumbers(k))
