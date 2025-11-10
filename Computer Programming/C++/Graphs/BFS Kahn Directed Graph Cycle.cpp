class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) 
    {
        // code here
        vector<vector<int>>adjlist(V);
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjlist[u].push_back(v);
        }
        
        vector<int>indegree(V,0);
        
        for(int i = 0;i<V;i++)
        {
            for(auto it : adjlist[i])
            {
                indegree[it] ++;
            }
        }
        
        queue<int>q;
        
        for(int i = 0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count ++;
            
            for(auto it:adjlist[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        if(count == V)
        {
            return false;
        }
        
        return true;
        
    }
};
