class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        int longest = 2;
        vector<unordered_map<int, int>> dp(n);
        int ans = 1;
        for(int i = 0; i<n;i++)
        {
            for(int j = i+1; j<n;j++)
            {
                int diff = nums[j] - nums[i];
                dp[j][diff] = dp[i].count(diff) ? dp[i][diff] + 1 : 2;

                ans = max(ans, dp[j][diff]);
            }
        }  

        return ans;
    }
};
