class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>vis(row,vector<int>(col,0));

        return function(vis,grid);    
    }

    bool function(vector<vector<int>>&vis,vector<vector<char>>&grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(vis[i][j]!= 1)
                {
                    char current = grid[i][j];
                    if(function2(vis,grid,current,i,j,-1,-1))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool function2(vector<vector<int>>&vis,vector<vector<char>>&grid,char current,int i,int j,int pi,int pj)
    {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        vis[i][j] = 1;
        for(int k = 0;k<4;k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
            {
                continue;
            }

            if(grid[ni][nj] != current)
                continue;

            if(ni == pi && nj == pj)
                continue;
            
            if(vis[ni][nj] == 1)
                return true;

            if(function2(vis,grid,current,ni,nj,i,j))
            {
                return true;
            }
        }
        return false;

    }
};
