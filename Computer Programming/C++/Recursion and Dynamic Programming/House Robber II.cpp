class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return nums[0];  
        
        int ans1 = function(nums,n-2,0);
        int ans2 = function(nums,n-1,1);

        return max(ans1,ans2);
    }

    int function(vector<int>&nums,int end,int start)
    {
        int len = end-start+1;
        vector<int> dp(len,0);
        if (len == 1) return nums[start];
        dp[0] = nums[start];
        dp[1] = max(nums[start+1],nums[start]);
        for(int i = 2; i<len;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2] + nums[start+i]);
        }

        return dp[len-1];

    }
};
