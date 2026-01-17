class Solution {
public:
    static const int MOD = 1e9 + 7;
    int knightDialer(int n) 
    {
        
        vector<vector<long long>>dp(n+1,vector<long long>(10,-1));
        long long total = 0;

        for(int i = 0;i<10;i++)
        {
            total = (total + function(dp,n - 1,i)) % MOD;
        }  

        return total;
    }

    long long function(vector<vector<long long>>&dp,long long n,int index)
    {
        if(n == 0)
        {
            return 1;
        }
        if(dp[n][index] != -1)
        {
            return dp[n][index];
        }

        long long total = 0;
        if(index == 0)
        {
            total += function(dp,n-1,4) + function(dp,n-1,6);
        }
        if(index == 1)
        {
            total += function(dp,n-1,6) + function(dp,n-1,8);
        }

        if(index == 2)
        {
            total += function(dp,n-1,7) + function(dp,n-1,9);
        }
        if(index == 3)
        {
            total += function(dp,n-1,4) + function(dp,n-1,8);
        }
        if(index == 4)
        {
            total += function(dp,n-1,3) + function(dp,n-1,9) + function(dp,n-1,0);
        }
        if(index == 5)
        {
            total += 0;
        }
        if(index == 6)
        {
            total += function(dp,n-1,1) + function(dp,n-1,7) + function(dp,n-1,0);
        }
        if(index == 7)
        {
            total += function(dp,n-1,6) + function(dp,n-1,2);
        }
        if(index == 8)
        {
            total += function(dp,n-1,1) + function(dp,n-1,3);
        }
        if(index == 9)
        {
            total += function(dp,n-1,4) + function(dp,n-1,2);
        }

        return dp[n][index] = total % MOD;
    }
};
