class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int text1size = text1.size();
        int text2size = text2.size();
        vector<vector<int>> dp(text1size,vector<int>(text2size,-1));
        int ans = function(text1,text1size - 1,text2,text2size - 1,dp);   
        return ans;
    }
        int function(string &text1, int index1, string &text2, int index2, vector<vector<int>>& dp)
        {
            if(index1<0 || index2<0)
            {
                return 0;
            }
            if(dp[index1][index2] != -1)
            {
                return dp[index1][index2];
            }

        if(text1[index1] == text2[index2])
        {
            return dp[index1][index2] = 1 + function(text1,index1-1,text2,index2-1,dp);
        }
        else
        {
            return dp[index1][index2] = max(function(text1,index1-1,text2,index2,dp), function(text1,index1,text2,index2-1,dp));
        }

        }
};
