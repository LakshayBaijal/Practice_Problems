// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<pair<int,int>>>adjlist(V);
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adjlist[u].push_back({v,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int>dist(V,INT_MAX);
        
        pq.push({0,0});
        dist[0] = 0;
        
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            if(dist[node] < weight)
            {
                continue;
            }
            
            for(auto it : adjlist[node])
            {
                int w = it.second;
                int next_node = it.first;
                
                if(dist[next_node] > w + weight)
                {
                    dist[next_node] = w + weight;
                    pq.push({dist[next_node],next_node});
                }
                
            }
        }
        
        for(int i = 0;i<V;i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
