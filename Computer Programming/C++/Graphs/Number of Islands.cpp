class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int column = grid[0].size();

        vector<vector<int>>vis(row,vector<int>(column,0));
        int ans = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<column;j++)
            {
                ans = ans + function(vis,grid,i,j);
            }
        }

        return ans;
    }

    int function(vector<vector<int>>&vis,vector<vector<char>>&grid,int i,int j)
    {

        int row = vis.size();
        int column = vis[0].size();

        if(i<0 || j<0 || i>=row || j>=column)
        {
            return 0;
        }
        if(vis[i][j] == 1 || grid[i][j] == '0')
        {
            return 0;
        }

        function2(vis,grid,i,j);
        return 1;
    }

    void function2(vector<vector<int>>&vis,vector<vector<char>>&grid,int i,int j)
    {
        int row = vis.size();
        int column = vis[0].size();
        if(i<0 || j<0 || i>=row || j>=column)
        {
            return;
        }
        if(vis[i][j] == 1 || grid[i][j] == '0')
        {
            return;
        }
        vis[i][j] = 1;

        function2(vis,grid,i-1,j);
        function2(vis,grid,i+1,j);
        function2(vis,grid,i,j-1);
        function2(vis,grid,i,j+1);
        return;

    }

};
