class Solution {
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int left = 0;
        int right = n-1;
        return function(left,values,dp,right);
    }

    int function(int left,vector<int>&values,vector<vector<int>>&dp,int right)
    {   

        if(right - left < 2)
        {
            return 0;
        }
        if(dp[left][right] != -1)
        {
            return dp[left][right];
        }
        int minimum = INT_MAX;
        for(int last = left+1;last<right;last++)
        {
            int current = values[left] * values[last] * values[right];
            int next = function(left,values,dp,last);
            int next_2 = function(last,values,dp,right);

            minimum = min({current+next+next_2,minimum});
        }

        dp[left][right] = minimum;
        return dp[left][right];
    }
};
