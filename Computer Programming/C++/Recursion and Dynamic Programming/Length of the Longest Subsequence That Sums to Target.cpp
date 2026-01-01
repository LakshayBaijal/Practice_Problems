class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        vector<int>current;
        
        int ans = function(dp,current,nums,target,n-1);    
        return ans < 0 ? -1 : ans;
    }
    
    int function(vector<vector<int>>&dp,vector<int>&current,vector<int>&nums,int target,int index)
    {
        if(target == 0)
        {
            return 0;
        }
        if(index < 0 || target < 0)
        {
            return INT_MIN;
        }
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int pick = INT_MIN;
        if (nums[index] <= target) 
        {
            int sub = function(dp, current, nums, target - nums[index], index - 1);
            if (sub != INT_MIN)
                pick = 1 + sub;
        }
        int notpick = function(dp,current,nums,target,index - 1);

        dp[index][target] = max(pick,notpick);

        return dp[index][target];

    }
    
};
