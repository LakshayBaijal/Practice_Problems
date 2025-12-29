class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        
        row = len(matrix)
        col = len(matrix[0])
        index = []
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    index.append((i,j))
        
        for it in index:
            row_i = it[0]
            col_j = it[1]
            for i in range(row):
                matrix[i][col_j] = 0
            for j in range(col):
                matrix[row_i][j] = 0

        
