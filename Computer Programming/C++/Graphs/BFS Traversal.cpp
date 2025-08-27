class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) 
    {
        // Code here
        int v = adj.size();
        queue<int>q;
        vector<int>vis(v,0);
        
        q.push(0);
        vector<int>bfs;
        vis[0] = 1;
        while(q.empty() == false)
        {
            int n = q.front();
            q.pop();
            
            bfs.push_back(n);
            
            for(auto it:adj[n])
            {
                if(vis[it] != 1)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
        
        
        
    }
};
