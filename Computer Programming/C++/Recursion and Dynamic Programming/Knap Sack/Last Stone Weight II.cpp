class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int n = stones.size();
        int total = 0;
        for(auto it : stones)
        {
            total += it;
        }   
        int sum = total;
        total = total / 2;

        vector<vector<int>>dp(n+1,vector<int>(total+1,0));

        for(int i = 1;i<=n;i++)
        {
            for(int j = 0;j<=total;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(stones[i-1] <= j)
                {
                    dp[i][j] = max(dp[i-1][j],stones[i-1] + dp[i-1][j-stones[i-1]]);
                }
            }
        }

        return sum -(2*dp[n][total]);
    }
};
