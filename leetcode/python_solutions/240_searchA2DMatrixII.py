class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        m = len(matrix)
        n = len(matrix[0])
        i = 0
        j = n - 1
        while( i < m and j >= 0):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False

    def searchMatrix1(self, matrix, target):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        n = len(matrix[0])
        for i in xrange(0, len(matrix)):
            if target < matrix[i][0]:
                return False
            if target > matrix[i][n-1]:
                continue
            left = 0
            right = n - 1
            while(left <= right):
                mid = (left+right)/2
                if matrix[i][mid] > target:
                    right = mid - 1
                elif matrix[i][mid] < target:
                    left = mid + 1
                else:
                    return True
        return False