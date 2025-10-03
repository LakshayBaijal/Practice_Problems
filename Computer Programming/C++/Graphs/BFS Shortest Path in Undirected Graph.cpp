class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) 
    {
        int n = adj.size();
        
        vector<int>vis(n,0);
        vector<int>distance(n,-1);
        queue<int>q;
        vis[src] = 1;
        distance[src] = 0;
        
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(vis[it] == 0)
                {
                    vis[it] = 1;
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        
        return distance;
    }
};
