class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])

        dp = []
        for i in range(0,row):
            curr = []
            for j in range(0,col):
                curr.append(-1)
            dp.append(curr)
        
        ans = self.function(dp,grid,row-1,col-1)
        return ans

    def function(self,dp,grid,row,col):
        if row == 0 and col == 0:
            return grid[0][0]
        if row < 0 or col < 0:
            return float('inf')
        if dp[row][col] != -1:
            return dp[row][col]
        
        left = self.function(dp,grid,row,col-1)
        down = self.function(dp,grid,row-1,col)

        dp[row][col] = min(left,down) + grid[row][col]
        return dp[row][col]
