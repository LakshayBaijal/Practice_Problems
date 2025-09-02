class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int v = isConnected[0].size();
        vector<vector<int>>adj(v);

        for(int i = 0; i<isConnected.size();i++)
        {
            for(int j = 0; j<v;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    if(i!=j)
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }  
        int ans = 0;
        int size = adj.size();
        vector<int>vis(size,0);

        for(int i = 0;i<adj.size();i++)
        {
            if(vis[i]!=1)
            {
                ans++;
                function(adj,vis,i);
            }
        }

        return ans;
    }

    void function(vector<vector<int>>&adj,vector<int>&vis,int index)
    {
        if(vis[index]==1)
        {
            return;
        }

        vis[index] = 1;
        for(auto it: adj[index])
        {
            function(adj,vis,it);
        }
        return;
    }
};
