class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<int>vis(n,0);

        queue<int> q;
        q.push(0);
        for(auto it : rooms[0])
        {
            q.push(it);

        }
        vis[0] = 1;   

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto &it : rooms[node])
            {
                    if(vis[it] == 0)
                    {   
                        q.push(it);
                        vis[it] = 1;
                    }   
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
};
