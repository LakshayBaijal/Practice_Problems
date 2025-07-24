class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>>vis(n,vector<int>(amount+1,-1));
        
        int ans = function(coins,n-1,amount,vis);
        return ans;
    }

    int function(vector<int>&coins , int index, int amount,vector<vector<int>>&vis)
    {
        if(amount==0)
        {
            return 1;
        }

        if(amount<0 || index<0)
        {
            return 0;
        }

        if(vis[index][amount]!= -1)
        {
            return vis[index][amount];
        }

        int pick = function(coins,index,amount-coins[index],vis);
        int notpick = function(coins,index-1,amount,vis);

        return vis[index][amount] = pick + notpick;
    }
};
