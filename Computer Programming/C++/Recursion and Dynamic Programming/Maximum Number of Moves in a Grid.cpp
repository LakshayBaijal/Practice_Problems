class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int total = 0;
        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i = 0;i<row;i++)
        {
            total = max(total,function(grid,dp,i,0));
        }    

        return total;
    }

    int function(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        if(i>=row || j>=col -1  || i<0)
        {
            return 0;
        }
        if(j==col-1)
        {
            return 1;
        }

        if (dp[i][j] != -1)
        return dp[i][j];

        int moves = 0;

        if(j<col-1)
        {
            if(i>0)
            {
                if(grid[i][j] < grid[i-1][j+1])
                {
                    moves = max(moves, 1 + function(grid,dp, i - 1, j + 1));     }
            }
                if(grid[i][j] < grid[i][j+1])
                {
                    moves = max(moves, 1 + function(grid,dp, i, j + 1));
                }

            if(i<row-1)
            {
                if(grid[i][j] < grid[i+1][j+1])
                {
                    moves = max(moves, 1 + function(grid,dp, i + 1, j + 1));
                }
            }
        }

        return dp[i][j] = moves;
    }
};
