class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>>adjlist(n+1);
        for(int i = 0;i<dislikes.size();i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }    

        queue<int>q;
        vector<int>vis(n+1,0);


        for(int i = 1;i<=n;i++)
        {
            if(vis[i] != 0)
            {
                continue;
            }
            q.push(i);
            vis[i] = 1;

            while(!q.empty())
            {
                int ele = q.front();
                q.pop();

                for(auto it : adjlist[ele])
                {
                    if(vis[it] == 0)
                    {
                        vis[it] = 3 - vis[ele];
                        q.push(it);
                    }

                    else if(vis[it] == vis[ele])
                    {
                        return false;
                    }  
            }
        }
        }

       

        return true;
    }
};
