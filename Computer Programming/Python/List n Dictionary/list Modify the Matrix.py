class Solution(object):
    def modifiedMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        row = len(matrix)
        col = len(matrix[0])
        max = []
        for i in range(col):
            temp = 0
            for j in range(row):
                if temp < matrix[j][i]:
                    temp = matrix[j][i]
            max.append(temp)

        for i in range(row):
            for j in range(col):
                if matrix[i][j] < 0:
                    matrix[i][j] = max[j]
        
        return matrix
