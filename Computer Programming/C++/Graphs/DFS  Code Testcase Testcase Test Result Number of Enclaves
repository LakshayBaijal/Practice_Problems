class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> vis(row,vector<int>(col,0));
        int total = 0;
        for(int i = 0;i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(i==0 || j==0 || i == row - 1 || j == col - 1)
                {
                    if(grid[i][j] == 1 && vis[i][j] == 0)
                    {
                        function2(grid,vis,i,j);
                    }
                }
            }
        }    

        for(int i = 0;i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                    if(grid[i][j] == 1 && vis[i][j] == 0)
                    {
                        total ++;
                    }
            }
        }    

        return total;
    }


    void function2(vector<vector<int>>&grid,vector<vector<int>>&vis,int i,int j)
    {
        int row = grid.size();
        int col = grid[0].size();

        if(i<0 || j<0 || i>=row || j>=col)
        {
            return;
        }

        if(vis[i][j] != 0 || grid[i][j] == 0)
        {
            return;
        }

        vis[i][j] = 1;
        function2(grid,vis,i-1,j);
        function2(grid,vis,i+1,j);
        function2(grid,vis,i,j-1);
        function2(grid,vis,i,j+1);
        return;
    }
};
