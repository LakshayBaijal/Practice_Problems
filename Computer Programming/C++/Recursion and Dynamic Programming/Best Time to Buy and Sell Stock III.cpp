class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(3,vector<int>(n+1,0));
        for(int k=1;k<=2;k++)
        {
            int min_price = prices[0];
            for(int i=1;i<prices.size();i++)
            {
min_price = min(min_price, prices[i] - dp[k-1][i-1]);
dp[k][i] = max(dp[k][i-1], prices[i] - min_price);

                dp[k][i] = max(dp[k][i-1], prices[i] - min_price);
            }
        }    
        return dp[2][prices.size() - 1];
    }
};
