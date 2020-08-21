
def print_matrix(matrix):
    for r in matrix:
        print(r)

# O(N^2)
class Solution(object):
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        
        for circle in range(n//2):
            r_circle = n - circle - 1
            for i in range(circle, n - circle - 1):
                a = matrix[circle][i]
                b, matrix[i][r_circle] = matrix[i][r_circle], a
                c, matrix[r_circle][n - i - 1] = matrix[r_circle][n - i - 1], b
                d, matrix[n - i - 1][circle] = matrix[n - i - 1][circle], c
                matrix[circle][i] = d


if __name__ == '__main__':
    print('Matrix row by row:')

    row = [int(v) for v in input().split(' ')]
    n = len(row)

    matrix = [row]
    for _ in range(1, n):
        row = [int(v) for v in input().split(' ')]
        if len(row) > n:
            raise RuntimeError('Should have been {} values'.format(n))
        else:
            matrix.append(row)
    
    Solution().rotate(matrix)
    print('Rotated:')
    print_matrix(matrix)

    
        