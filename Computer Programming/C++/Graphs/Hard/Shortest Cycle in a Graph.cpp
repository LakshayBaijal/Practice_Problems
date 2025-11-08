class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adjlist(n);
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }     
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int temp = function(adjlist ,n, i);
            ans = min(ans, temp);
        }
        return (ans == INT_MAX) ? -1 : ans;


    }

    int function(vector<vector<int>>&adjlist,int n,int source)
    {
        vector<int>dist(n,-1);
        vector<int>parent(n,-1);
        int minimum = INT_MAX;
        dist[source] = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adjlist[node])
            {
                if(dist[it] == -1)
                {
                    dist[it] = dist[node] + 1;
                    parent[it] = node;
                    q.push(it);
                }
                else if(it != parent[node])
                {
                    minimum = min(minimum,dist[node] + dist[it] + 1);
                }
            }
        }
        return minimum;
    }
};
