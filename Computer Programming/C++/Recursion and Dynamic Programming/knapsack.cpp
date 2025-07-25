 int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // code here
        
        int n =  val.size();

        vector<vector<int>> dp(n + 1,vector<int>(W + 1,0));
        
        for(int i = 1;i<=n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(dp[i][j], val[i-1] + dp[i-1][j-wt[i-1]]);
                }
            }
        }
        
        return dp[n][W];
    }
