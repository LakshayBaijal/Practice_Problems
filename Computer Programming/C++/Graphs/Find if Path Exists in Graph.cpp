class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>>adj(n);

        for(int i = 0; i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }    

        vector<int>vis(n,0);

        bool ans = false;
        ans = function(vis,adj,source,destination);
        return ans;
    }

    bool function(vector<int>&vis,vector<vector<int>>&adj,int index,int destination)
    {
        if(index == destination)
        {
            return true;
        }

        if(vis[index]==1)
        {
            return false;
        }
        vis[index] = 1;
        for(auto it:adj[index])
        {
            if(vis[it] != 1)
            {
                if(function(vis,adj,it,destination))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
