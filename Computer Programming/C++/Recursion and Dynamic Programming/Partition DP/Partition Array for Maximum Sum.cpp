class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int>dp(n,-1);
        return function(dp,arr,k,0);   
    }

    int function(vector<int>&dp,vector<int>&arr,int k,int index)
    {

        int n = arr.size();
        if(index == n)
        {
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int best = 0;
        int currmax = 0;

        for(int len = 0;len<k && len + index < n ;len++)
        {
            currmax = max(currmax,arr[index + len]);
            best = max({best,currmax * (len+1) + function(dp,arr,k,len+index+1)});
        }

        return dp[index] = best;
    }
};
