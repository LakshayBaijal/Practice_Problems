class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int total = 0;
        vector<int>a;
        a.push_back(1);
        a.insert(a.end(),nums.begin(),nums.end());
        a.push_back(1);
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,a,dp);
    }

    int solve(int left,int right,vector<int>&a,vector<vector<int>>&dp)
    {
        if(right - left < 0)
        {
            return 0;
        }
        if(dp[left][right] != -1)
        {
            return dp[left][right];
        }
        int best = 0;

        for(int last = left + 1; last<right;last++)
        {
            int coins_now = a[last] * a[left] * a[right];
            int coins_left = solve(left,last,a,dp);
            int coins_right = solve(last,right,a,dp);

            best = max(best,coins_now + coins_left + coins_right);
        }

        dp[left][right] = best;
        return dp[left][right];
    }
};
