class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>squares;
        for(int i = 1; i*i<=n; i++)
        {
            squares.push_back(i*i);
        }
        int size = squares.size();

        vector<vector<int>>vis(size,vector<int>(n+1,-1));

        int ans = function(squares,vis,n,size-1);
        return ans;
    }

    int function(vector<int> &squares,vector<vector<int>> &vis,int n,int index)
    {
        if(index < 0)
        {
            return INT_MAX;
        }
        if(n == 0)
        {
            return 0;
        }
        if(vis[index][n] != -1)
        {
            return vis[index][n];
        }
        int pick = INT_MAX;
        if(n>=squares[index])
        {
        int ass = function(squares,vis,n - squares[index],index);
        if(ass != INT_MAX)
        {
            pick = ass + 1;
        }
        }

        int notpick = function(squares,vis,n,index-1);

        return vis[index][n] = min(pick,notpick);

    }
};
