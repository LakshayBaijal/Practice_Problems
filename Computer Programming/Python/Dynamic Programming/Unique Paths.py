class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        dp = []
        for i in range(0,m):
            curr = []
            for j in range(0,n):
                curr.append(-1)
            dp.append(curr)


        return self.function(dp,m-1,n-1)

    def function(self,dp,row,col):
        if row == 0 and col == 0:
            return 1
        if row < 0 or col < 0:
            return 0
    
        if dp[row][col] != -1:
            return dp[row][col]

        left = self.function(dp,row,col-1)
        down = self.function(dp,row-1,col)

        dp[row][col] = left + down
        return dp[row][col]
