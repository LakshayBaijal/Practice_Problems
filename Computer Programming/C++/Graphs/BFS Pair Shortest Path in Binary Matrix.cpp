class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 1 && col == 1)
        {
            return 1;
        }

        queue<pair<int,int>>q;

        if(grid[0][0] == 1 || grid[row-1][col-1] == 1)
        {
            return -1;
        }

        q.push({0,0});
        vector<vector<int>>vis(row,vector<int>(col,0));
        int dirR[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int dirC[8] = {1, 0, -1, 0, 1, -1, 1, -1};
        vis[0][0] = 1;
        vector<vector<int>>dist(row,vector<int>(col,0));
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0;k<8;k++)
            {
                int new_i = i + dirR[k];
                int new_j = j + dirC[k];
                
                if(new_i < 0 || new_j < 0 || new_i >= row || new_j >= col || grid[new_i][new_j] == 1) 
                {
                continue;
                }
                if(vis[new_i][new_j] == 1)
                {
                    continue;
                }
                dist[new_i][new_j] = dist[i][j] + 1;
                if(new_i == row - 1 && new_j == col -1)
                {
                    return dist[new_i][new_j] + 1;
                }

                vis[new_i][new_j] = 1;
                q.push({new_i,new_j});
                
            }

        }
        return -1;

    }
}; 
