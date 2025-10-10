O(n2)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        int n = arr.size();
        vector<int>dp(n+1,1);


        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] - arr[j] == difference)
                {
                    dp[i] = max(dp[j] + 1,dp[i]);
                }
            }
        }
        int maxlen = 0;
        for(auto it:dp)
        {
            if(maxlen < it)
            {
                maxlen = it;
            }
        }    

        return maxlen;
    }
};




O(n)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        unordered_map<int,int> dp;
        int ans = 0;
        for(auto it:arr)
        {
            dp[it] = dp[it - difference] + 1;
            ans = max(ans,dp[it]);
        }


        return ans;
    }
};
