class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int> mp;

        for(auto it : nums)
        {
            mp[it] ++;
        }    

        for(auto &it : mp)
        {
            int ele = it.first;
            int freq = it.second;

            pq.push({freq,ele});
        }
        vector<int>ans;
        while(!pq.empty())
        {
            int ele = pq.top().second;
            int freq = pq.top().first;

            ans.push_back(ele);
            k--;
            if(k==0)
            {
                return ans;
            }
            pq.pop();
        }
        return ans;
    }
};
