class Solution {
public:

    const int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) 
    {
        int total = 0;
        vector<vector<int>>dp(n+1,vector<int>(target + 1,-1));

        int ans = function(dp,n,k,target);
        return ans;
    }

    int function(vector<vector<int>>&dp,int index,int k, int target)
    {
        if(index == 0)
        {
            if(target == 0)
            {
                return 1;
            }
            return 0;
        }
        if(index < 0 || target < 0)
        {
            return 0;
        }
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        int ans = 0;
        for(int i = 1;i<=k;i++)
        {   
            if(target >= i)
            {
                ans = (ans+function(dp,index - 1,k,target - i)) % MOD;
            }
        }

        return dp[index][target] = ans;
    }
};
