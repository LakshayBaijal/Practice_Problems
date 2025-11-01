class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>adjlist(n);
        for(int i = 0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];    
            adjlist[u].push_back(-v);
            adjlist[v].push_back(u);
        }

        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adjlist[node])
            {
                int next = abs(it);
                if(vis[next] == 0)
                {
                    vis[next] = 1;
                    q.push(next);
                    if(it < 0)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
          
    }
};
