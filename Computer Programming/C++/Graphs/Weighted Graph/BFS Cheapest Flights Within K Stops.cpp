class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {

        vector<pair<int,int>>adjlist[n];

        for(auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adjlist[u].push_back({v,w});
        }

        queue<pair<int,pair<int,int>>> q;

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            int stop = q.front().first;
            int node = q.front().second.first;
            int totalweight = q.front().second.second;
            q.pop();
            if(k < stop)
            {
                continue;
            }

            for(auto &it : adjlist[node])
            {
                int adjnode = it.first;
                int weight = it.second;
                
                if(totalweight + weight < dist[adjnode] && stop <= k)
                {
                    dist[adjnode] = totalweight + weight;
                    q.push({stop+1,{adjnode,totalweight + weight}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};
