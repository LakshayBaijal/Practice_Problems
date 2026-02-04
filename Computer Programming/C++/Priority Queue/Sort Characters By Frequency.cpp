class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> mp;

        for(auto it : s)
        {
            mp[it] ++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty())
        {
            char s = pq.top().second;
            int i = pq.top().first;

            while(i!=0)
            {
                ans.push_back(s);
                i--;
            }
            pq.pop();
        }

        return ans;

    }
};
