class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int row = isConnected.size();
        int col = isConnected[0].size();

        vector<vector<int>> adjlist(row);

        for(int i = 0; i < row;i++)
        {
            for(int j = 0; j < col;j++)
            {
                if(i!=j && isConnected[i][j] == 1)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        queue<int>bfs;
        int ans = 0;
        vector<int>vis(row,0);


        for(int i = 0;i<row;i++)
        {
            if(vis[i] == 0)
            {
                ans++;


                 bfs.push(i);
            vis[i] = 1;
            while(!bfs.empty())
        {
            int n = bfs.front();
            bfs.pop();

            for(auto it : adjlist[n])
            {
                if(vis[it] == 0)
                {
                    bfs.push(it);
                    vis[it] = 1;
                }
            }

            }
           
        }
        }

        return ans;

    }
};
