class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])

        dp = []
        for i in range(0,row):
            curr = []
            for j in range(0,col):
                curr.append(-1)
            dp.append(curr)
        

        ans = self.function(dp,obstacleGrid,row-1,col-1)
        return ans

    def function(self,dp,obstacleGrid,row,col):
        if row == 0 and col == 0:
            return 1
        if row < 0 or col < 0:
            return 0
        if dp[row][col] != -1:
            return dp[row][col]
        
        if obstacleGrid[row][col] == 1:
            return 0

        left = self.function(dp,obstacleGrid,row-1,col)
        down = self.function(dp,obstacleGrid,row,col-1)

        dp[row][col] = left + down
        return dp[row][col]
