// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) 
    {
        // Code here
        vector<vector<pair<int,int>>>adjlist(V);
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adjlist[u].push_back({v,w});
            adjlist[v].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(V,INT_MAX);
        pq.push({0,src});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it:adjlist[node])
            {
                int u = it.first;
                int w = it.second; 
                if(dist[node] + w < dist[u])
                {
                    dist[u] = dist[node] + w;
                    pq.push({dist[u],u});
                }
            }
        }
        
        return dist;
        
        

        
    }
};
