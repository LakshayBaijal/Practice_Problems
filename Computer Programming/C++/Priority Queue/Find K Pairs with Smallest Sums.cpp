class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        for(int i = 0;i<nums1.size();i++)
        {
            for(int j = 0;j<nums2.size();j++)
            {
                int total = nums1[i] + nums2[j];
                pq.push({total,{nums1[i],nums2[j]}});
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            int left = pq.top().second.first;
            int right = pq.top().second.second;

            k--;
            ans.push_back({left,right});
            if(k == 0)
            {
                return ans;
            }

            pq.pop();
        }
        return ans;
    }
};
