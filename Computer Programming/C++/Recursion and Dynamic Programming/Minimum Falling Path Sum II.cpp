class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size(); 

        vector<vector<int>>dp(row,vector<int>(col,-1));
        int ans = INT_MAX;
     
        for(int i = 0;i<col;i++)
        {
            int temp = INT_MAX;
            temp = function(grid,dp,row -1 ,i);
            ans = min(ans,temp);
        } 

        return ans;
    }

    int function(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0||j<0)
        {
            return INT_MAX;
        }
        if(j>=grid[0].size())
        {
            return INT_MAX;
        }
        if(i == 0)
        {
            return grid[0][j];
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int best = INT_MAX;
        for(int k = 0;k<grid[0].size();k++)
        {
            if(k != j)
            {
                best = min(best,function(grid, dp, i - 1, k));
            }
            
            
        }

        return dp[i][j] = best + grid[i][j];

        
    }


};
