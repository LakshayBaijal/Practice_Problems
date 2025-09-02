class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(column,0));
        int max = 0;
        int area = 0;
        for(int i = 0; i<row;i++)
        {
            for(int j = 0; j<column;j++)
            {
                if(vis[i][j]==0)
                {
                area = function1(vis,grid,i,j);
                }

                if(area >= max)
                {
                    max = area;
                }
            }
        }
        return max;
    }

    int function1(vector<vector<int>>&vis,vector<vector<int>>&grid,int i,int j)
    {
        int row = grid.size();
        int column = grid[0].size();

        if(i<0 || j<0 || i>=row || j>=column)
        {
            return 0;
        }

        if(vis[i][j] == 1 || grid[i][j] == 0)
        {
            return 0;
        }

        return function2(vis,grid,i,j);
    }

    int function2(vector<vector<int>>&vis,vector<vector<int>>&grid,int i,int j)
    {
        int row = grid.size();
        int column = grid[0].size();

        if(i<0 || j<0 || i>=row || j>=column)
        {
            return 0;
        }

        if(vis[i][j] == 1 || grid[i][j] == 0)
        {
            return 0;
        }

        vis[i][j] = 1;
        
        int up = function2(vis,grid,i,j+1);
        int down = function2(vis,grid,i,j-1);
        int left = function2(vis,grid,i-1,j);
        int right = function2(vis,grid,i+1,j);

        int area = grid[i][j] + up + down + left + right;

        return area;
    }


};
