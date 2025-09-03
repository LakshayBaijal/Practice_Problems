class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int>vis(v,0);

        queue<int>q;


        for(int start = 0;start < v;start++)
        {
            if(vis[start]!=0)
            {
                continue;
            }
        q.push(start);
        vis[start] = 1;
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            
            for(auto it : graph[index])
            {
                if(vis[it] == 0)
                {
                    if(vis[index] == 1)
                    {
                        vis[it] = 2;
                    }
                    else
                    {
                        vis[it] = 1;
                    }
                    q.push(it);
                }

                else if(vis[it] == vis[index])
                {
                    return false;
                }
            }
        }
        }
        return true;

    }
};
