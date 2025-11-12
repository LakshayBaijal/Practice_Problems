class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int>vis(v,-1);
        for(int i = 0;i<v;i++)
        {
            if(vis[i] == -1)
            {
                if(!function(graph,0,vis,i))
                {
                    return false;
                }
            }
        }    
        return true;
    }

    bool function(vector<vector<int>>&graph,int col,vector<int>&vis,int index)
    {
        vis[index] = col;
        for(auto it : graph[index])
        {
            if(vis[it] == -1)
            {
                if(!function(graph,!col,vis,it))
                {
                    return false;
                }

            }
            else if(vis[it] == col)
                {
                    return false;
                }
        }
        return true;
    }
};
