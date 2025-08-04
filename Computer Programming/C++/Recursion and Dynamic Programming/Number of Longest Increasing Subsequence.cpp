class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1,1);
        vector<int> count(n+1,1);

        for(int i = 1; i<n;i++)
        {
            for(int j = 0; j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j]+1)
                    {
                        count[i] += count[j];
                    }
                }
            }
        }  

        int max = *max_element(dp.begin(),dp.end());
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == max) {
                total += count[i];
            }
        }

        return total;


    }
};
