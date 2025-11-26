class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>> adjlist(n);
        for(auto &it : roads)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adjlist[u].push_back({v,w});
            adjlist[v].push_back({u,w});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});
        long long mod = 1e9 + 7;
        while(!pq.empty())
        {
            long long weight = pq.top().first;
            long long node = pq.top().second;

            pq.pop();
            if(weight > dist[node]) continue;

            for(auto it : adjlist[node])
            {
                long long adjnode = it.first;
                long long w = it.second;

                if(w + weight < dist[adjnode])
                {
                    dist[adjnode] = w + weight;
                    ways[adjnode] = ways[node];
                    pq.push({w+weight,adjnode});
                }
                else if(w + weight == dist[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        } 

        return ways[n-1];


    }
};
