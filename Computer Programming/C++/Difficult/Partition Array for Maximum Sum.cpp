class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int>dp(n+1,-1);    

        int ans = function(arr,k,dp,0);

        return ans;
    }

    int function(vector<int>&arr,int k,vector<int>&dp,int index)
    {
        int n = arr.size();
        if(n == index)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        int currmax = 0;
        int best = 0;

        for(int len = 0;len<k && len + index<n;len++)
        {
            currmax = max(currmax,arr[len+index]);
            best = max(best, currmax * (len + 1) +  function(arr,k,dp,len + index +1 ));
        }

        return dp[index] = best;
    }
};
