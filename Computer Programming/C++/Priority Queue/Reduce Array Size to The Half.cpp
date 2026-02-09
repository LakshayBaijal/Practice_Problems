class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int,int> mp;
        for(auto it : arr)
        {
            mp[it] ++;
        }   

        priority_queue<pair<int,int>>pq;

        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }

        int count = 0;
        int ans = 0;
        while(!pq.empty())
        {
            int freq = pq.top().first;
            count += freq;
            ans ++;
            if(arr.size() / 2 <= count)
            {
                return ans;
            }
            pq.pop();
        }

        return count;
    }
};
