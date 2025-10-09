Inefficient Way

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>adjlist(n);

        for(auto &e : connections)
        {
            int u = e[0];
            int v = e[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);

        }

        int ans = 0;
        vector<int>vis(n,0);
        function(vis,adjlist,connections,0,ans);
        return ans;
    }

    void function(vector<int>&vis,vector<vector<int>>&adjlist,vector<vector<int>>&connections,int index,int &ans)
    {
        if(vis[index] == 1)
        {
            return;
        }
        vis[index] = 1;
        for(auto it : adjlist[index])
        {
            if(vis[it] == 0)
            {

            
            for(auto &e:connections)
            {
            int u = e[0];
            int v = e[1];

            if(u == index && v == it)
            {
                ans++;
                break;
            }
            }

            function(vis,adjlist,connections,it,ans);
            }
        }
        return;
    }
};


Efficient Way

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>adjlist(n);

        for(auto &e : connections)
        {
            int u = e[0];
            int v = e[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(-u);

        }

        int ans = 0;
        vector<int>vis(n,0);
        function(vis,adjlist,connections,0,ans);
        return ans;
    }

    void function(vector<int>&vis,vector<vector<int>>&adjlist,vector<vector<int>>&connections,int index,int &ans)
    {
        if(vis[index] == 1)
        {
            return;
        }
        vis[index] = 1;
        for(auto it : adjlist[index])
        {
            int next = abs(it);
            if(vis[next] == 0)
            {
                if(it>0)
                {
                    ans++;
                }
            }
            function(vis,adjlist,connections,next,ans);
        }

        return;
    }
};
