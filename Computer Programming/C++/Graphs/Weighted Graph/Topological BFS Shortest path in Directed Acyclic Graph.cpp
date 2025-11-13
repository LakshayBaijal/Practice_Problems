// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
    {
        // code here
        
        vector<vector<pair<int,int>>>adjlist(V);
        for(int i = 0;i<E;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjlist[u].push_back({v,w});
        }
        
        vector<int>indegree(V,0);
        
        for(int i = 0;i<V;i++)
        {
            for(auto &it:adjlist[i])
            {
                indegree[it.first] ++;
            }
        }
        queue<int>q;        
        for(int i = 0;i<V;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> topo;

        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto &it : adjlist[node])
            {
                int vertices = it.first;
                indegree[vertices]--;
                if(indegree[vertices] == 0)
                {
                    q.push(vertices);
                }
            }
        }
        vector<int>dist(V,INT_MAX);
        dist[0] = 0;

        for(int vertice : topo)
        {
            if(dist[vertice] == INT_MAX)
            {
                continue;
            }
            
            for(auto &it : adjlist[vertice])
            {
                int v = it.first;
                int w = it.second;
                
                if(dist[v] > dist[vertice] + w)
                {
                    dist[v] = dist[vertice] + w;
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
