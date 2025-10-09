class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adjlist(n);
        for(auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }   

        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0;i < n; i++)
        {
            if(vis[i] == 0)
            {
                int totaledge = 0;
                int totalnodes = 0;
                dfs(adjlist,vis,totaledge,totalnodes,i);

                if(totaledge == totalnodes * (totalnodes - 1))
                {
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>&adjlist,vector<int>&vis,int &totaledge,int &totalnodes,int index)
    {
        totalnodes ++;
        totaledge += adjlist[index].size();
        vis[index] = 1;
        for(auto it:adjlist[index])
        {
            if(vis[it] == 0)
            {
                dfs(adjlist,vis,totaledge,totalnodes,it);
            }
        }
        return;
    }

};
