// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) 
    {
        // Code here
        vector<vector<pair<int,int>>> adjlist(V);
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        for(int i = 0;i<V;i++)
        {
            for(auto &it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != INT_MAX && dist[v] > w + dist[u])
                {
                    dist[v] = w + dist[u];
                }
            }
        }

            for(auto &it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != INT_MAX && dist[v] > w + dist[u])
                {
                    return {-1};
                }
            }
        return dist;
    }
};
