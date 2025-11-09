class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) 
    {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        vector<vector<int>>dp(row,vector<int>(col,INT_MAX));
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    dp[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();
            
            for(int k = 0;k<4;k++)
            {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                
                if(nx>=0&&ny>=0&&nx<row&&ny<col)
                {
                    if(vis[nx][ny] == 0)
                    {
                        vis[nx][ny] = 1;
                        dp[nx][ny] = dp[i][j] + 1;
                        q.push({nx,ny});
                    } 
                }

                
            }
        }
        
        return dp;
        
        

        
        
    }
};
