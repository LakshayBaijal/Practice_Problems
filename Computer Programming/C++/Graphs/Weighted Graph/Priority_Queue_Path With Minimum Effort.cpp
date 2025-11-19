class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int row = heights.size();
        int col = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>  pq;

        vector<vector<int>>dp(row,vector<int>(col,INT_MAX));

        dp[0][0] = 0;
        pq.push({0,{0,0}});

        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};

        while(!pq.empty())
        {
            int diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int min = INT_MAX;
            pq.pop();
            for(int k = 0;k<4;k++)
            {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if(new_i<0 || new_j<0 || new_i >= row || new_j >= col)
                {
                    continue;
                }
                int new_effort = max(diff, abs(heights[i][j] - heights[new_i][new_j]));
                if(dp[new_i][new_j] > new_effort)
                {
                    dp[new_i][new_j] = new_effort;
                    pq.push({dp[new_i][new_j],{new_i,new_j}});
                }
                
                

            }       
        }
        return dp[row-1][col-1];

    }
};
