// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        // code here
        int n = arr.size();
        queue<pair<int,int>> q;
        vector<int> dist(100000, INT_MAX);

        if(end == start)
        {
            return 0;
        }
        q.push({0, start});
        dist[start] = 0;        
        while(!q.empty())
        {
            int current = q.front().second;
            int step = q.front().first;
            
            q.pop();
            for(auto it : arr)
            {   
                int num = (it * current) % 100000;
                if(dist[num] > step + 1)
                {
                    if(num == end)
                    {
                        return step + 1;
                    }
                    dist[num] = step + 1;
                    q.push({step+1,num});
                }

            }
        }
        
        return -1;
        
    }
};
