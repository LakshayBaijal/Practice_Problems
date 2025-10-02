class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        
        for(auto & e : edges)
        {
            vector<int> vis(n+1,-1);
            int u = e[0];
            int v = e[1];

            if(!adj[u].empty() && !adj[v].empty())
            {
                if(function(u,v,vis,adj))
                {
                    return e;
                }
            }
                adj[u].push_back(v);
                adj[v].push_back(u);
            
        }

        return {};
    }

    bool function(int u,int target,vector<int>&vis,vector<vector<int>>&adj)
    {
        if(u == target)
        {
            return true;
        }

        vis[u] = 1;

        for(auto it : adj[u])
        {
            if(vis[it] == -1)
            {
                if(function(it,target,vis,adj))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
