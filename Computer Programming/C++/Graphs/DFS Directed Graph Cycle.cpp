class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) 
    {
        // code here
        
        
        vector<vector<int>>adjlist(V);
        
        for(int i = 0; i < edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);

        for(int i = 0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                if(function(vis,pathvis,adjlist,i))
                {
                    return true;
                }                
            }

            
        }
        
        return false;
    }
    
    bool function(vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adjlist,int index)
    {
        if(vis[index] == 1)
        {
            return false;
        }
        
        vis[index] = 1;
        pathvis[index] = 1;
        
        for(auto it : adjlist[index])
        {
            if(vis[it] != 1)
            {
                if(function(vis,pathvis,adjlist,it))
                return true;
            }
            
            else if(pathvis[it])
            {
                return true;
            }
        }
        
        pathvis[index] = 0;
        return false;
    }
};
