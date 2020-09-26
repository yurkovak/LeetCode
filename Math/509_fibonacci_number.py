
# O(N)
class Solution:
    def fib(self, N):
        if N <= 1:
            return N

        prev_prev, prev = 0, 1
        for _ in range(2, N + 1):
            cur = prev_prev + prev
            prev_prev = prev
            prev = cur

        return prev


if __name__ == '__main__':
    N = int(input('n = '))
    print('Fibonacci number, F(n) =', Solution().fib(N))