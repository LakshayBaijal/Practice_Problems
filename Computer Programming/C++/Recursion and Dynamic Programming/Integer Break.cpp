class Solution {
public:
    int integerBreak(int n) 
    {
        vector<vector<int>> vis(n+1,vector<int>(n+1,-1));
        int ans = function(vis,n-1,n);
        
        return ans;
    }

    int function(vector<vector<int>>&vis,int index,int target)
    {
        if(index<=0)
        {
            return 0;
        }
        if(target == 0)
        {
            return 1;
        }
        if(target<0)
        {
            return 0;
        }
        if(vis[index][target] != -1)
        {
            return vis[index][target];
        }

        int pick = INT_MIN;
        if(target >= index)
        {
            pick = index * function(vis,index,target - index);
        }


        int notpick = function(vis,index-1,target);

        return vis[index][target] = max(pick,notpick);
    }   
};
