class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = function(s,rev,dp,n-1,n-1);
        return ans;
    }

    int function(string &s, string &rev, vector<vector<int>> &dp,int index1,int index2)
    {
        if(index1<0 || index2<0)
        {
            return 0;
        }
        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }

        if(s[index1] == rev[index2])
        {
            return dp[index1][index2] = 1 + function(s,rev,dp,index1-1,index2-1);
        }
        else
        {
            return dp[index1][index2] = max(function(s,rev,dp,index1-1,index2),function(s,rev,dp,index1,index2-1));
        }
    }
};
