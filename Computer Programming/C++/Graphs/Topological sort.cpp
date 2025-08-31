class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        
        vector<vector<int>>adj(V);
        
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>dfs;
        vector<int>vis(V,0);
        
        for(int i = 0;i < adj.size();i++)
        {
            function(adj,dfs,vis,i);
        }
        reverse(dfs.begin(),dfs.end());
        return dfs;
    }
    
    void function(vector<vector<int>>&adj,vector<int>&dfs,vector<int>&vis,int index)
    {
        if(vis[index] == 1)
        {
            return;
        }
        vis[index] = 1;
        
        for(auto it:adj[index])
        {
            
            function(adj,dfs,vis,it);
        }
        dfs.push_back(index);
        return;
    }
    
};
