class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>vis(row,vector<int>(col,0));

        vis[0][0] = 1;
        int w = grid[0][0];

        pq.push({w,{0,0}});

        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};  
        int ans = 0;
        while(!pq.empty())
        {
            int currenttime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int weight = grid[i][j];

            ans = max(ans, currenttime);

            if(i == row-1 && j == col-1) 
            return ans;

            pq.pop();
            
            for(int k = 0;k<4;k++)
            {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if(new_i < 0 || new_j < 0 || new_i >= row || new_j >= col)
                {
                    continue;
                }

                if(!vis[new_i][new_j])
                {
                    currenttime = grid[new_i][new_j];
                    vis[new_i][new_j] = 1;
                    pq.push({grid[new_i][new_j],{new_i,new_j}});
                }
                
            }

        }
        return ans;
    }
};
