class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size();
        vector<int>dp(n,0);
        vector<int>vis(n,0);
        int maximum = -1;
        for(int i = 0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                function(dp,vis,edges,i,0,maximum);
            }
        }    
        return maximum;
    }

    void function(vector<int>&dp,vector<int>&vis,vector<int>&edges,int index,int dist,int &maximum)
    {
        if(vis[index] != 0)
        {
            return;
        }
        
        vis[index] = 1;
        dp[index] = dist;

        int next = edges[index];

        if(next != -1)
        {
            if(vis[next] == 0)
            {
                function(dp,vis,edges,next,dist + 1,maximum);
            }
            if(vis[next] == 1)
            {
                maximum = max(maximum,(dist - dp[next] + 1));
            }
        }

        vis[index] = 2;
        return;
    }
};
