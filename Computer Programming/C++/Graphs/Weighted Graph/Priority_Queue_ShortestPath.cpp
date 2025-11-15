class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        // Code here
        vector<vector<pair<int,int>>> adjlist(n + 1);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adjlist[u].push_back({v,w});
            adjlist[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1);
        
        for(int i = 0;i<n+1;i++)
        {
            parent[i] = i;
        }
        
        dist[1] = 0;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(weight > dist[node]) continue;
            for(auto &it:adjlist[node])
            {
                int u = it.first;
                int w = it.second;
                
                if(dist[u] > dist[node] + w)
                {
                    dist[u] = dist[node] + w;
                    pq.push({dist[u],u});
                    parent[u] = node; 
                }
            }
        }
        vector<int>path;
        int node = n;
        while(parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
        
    }
};
