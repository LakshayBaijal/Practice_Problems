class Solution {
public:
    int minimumDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
        }

        vector<vector<int>>dp(n,vector<long long>(sum/2 + 1,-1));

        int leftsum = sum/2 - function(dp,nums,sum/2,n-1);
        int rightsum = sum - leftsum;

        return abs(rightsum - leftsum);
    }

    int function(vector<vector<long long>>&dp,vector<int>&nums,int total,int index)
    {
        if(total == 0)
        {
            return 0;
        }
        if(index<0)
        {
            return total;
        }
        if(dp[index][total]!=-1)
        {
            return dp[index][total];
        }
        int pick = INT_MAX;
        if(nums[index] <= total)
        {
            pick = function(dp,nums,total - nums[index],index - 1);
        }
        
        int notpick = function(dp,nums,total,index - 1);

        return dp[index][total] = min(pick, notpick);
    }
};
