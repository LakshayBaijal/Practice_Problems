class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        int temp = function(dp,str1,str2,n1,n2);
        string ans = "";

        int index1 = n1;
        int index2 = n2;

        while(index1 > 0 && index2 > 0)
        {
            if(str1[index1 - 1] == str2[index2 - 1])
            {
                ans.push_back(str1[index1 - 1]);
                index1--;
                index2--;
            }
            else if(dp[index1-1][index2] > dp[index1][index2-1])
            {
                ans.push_back(str1[index1 - 1]);
                index1--;
            }
            else
            {
                ans.push_back(str2[index2 - 1]);
                index2--;
            }
        }
            while(index1>0)
            {
                ans.push_back(str1[index1 - 1]);
                index1--;
            }
            while(index2>0)
            {
                ans.push_back(str2[index2 - 1]);
                index2--;
            }
            reverse(ans.begin(), ans.end());
            return ans;
    }

    int function(vector<vector<int>>&dp,string &str1,string &str2,int index1,int index2)
    {
        if(index1 == 0 || index2 == 0)
        {
            return 0;
        }

        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }

        if(str1[index1 - 1] == str2[index2 - 1])
        {
            dp[index1][index2] = 1 + function(dp,str1,str2,index1 - 1,index2 - 1);
            return dp[index1][index2];
        }
        else
        {
            dp[index1][index2] = max(function(dp,str1,str2,index1,index2 - 1),function(dp,str1,str2,index1 - 1,index2));
            return dp[index1][index2];
        }
    }
};
