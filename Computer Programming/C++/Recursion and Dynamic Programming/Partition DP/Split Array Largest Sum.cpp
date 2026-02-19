class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));

        return function(nums,k,dp,0);  
    }

    int function(vector<int>&nums,int k,vector<vector<int>>&dp,int index)
    {
        int n = nums.size();
        if(n == index)
        {
            return INT_MAX;
        }
        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }

        if(k == 1)
        {
            int total = 0;
            for(int i = index;i<n;i++)
            {
                total += nums[i];
            }

            return total;
        }

        int currsum = 0;
        int best = INT_MAX;

        for(int len = 0;len + index < n; len++)
        {
            currsum += nums[len + index];
            best = min(best, max(currsum,function(nums,k-1,dp,index + len + 1)));
            
        }

        dp[index][k] = best;
        return best;
    }
};
