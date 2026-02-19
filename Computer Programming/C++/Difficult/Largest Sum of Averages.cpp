class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<vector<double>>dp(n,vector<double>(k+1,-1));

        double ans = function(nums,k,dp,0);   
        return ans;
    }

    double function(vector<int>&nums,int k,vector<vector<double>>&dp,int index)
    {
        int n = nums.size();
        if(index == n)
        {
            return 0;
        }

        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }

        if(k == 1)
        {
            double total = 0;
            for(int i = index;i<n;i++)
            {
                total += nums[i];
            }
            return dp[index][k] = total / (n - index);
        }

        double totalsum = 0;
        double best = 0;

        for(int len = 0;len+index<n;len++)
        {
            totalsum = totalsum + nums[index + len];
            double avg = totalsum / (len+1);
            best = max(best, avg + function(nums,k-1,dp,index+len + 1));
        }

        dp[index][k] = best;
        return dp[index][k];
    }
};
