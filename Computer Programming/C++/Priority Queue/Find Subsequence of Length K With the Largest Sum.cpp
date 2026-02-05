class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>>pq;

        for(int i = 0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }    

        priority_queue<int,vector<int>,greater<int>>sort;

        while(k>0)
        {
            int sortedelement = pq.top().first;
            int position = pq.top().second;
            pq.pop();

            sort.push(position);
            k--;
        }

        vector<int>ans;
        while(!sort.empty())
        {
            int index = sort.top();
            ans.push_back(nums[index]);
            sort.pop();
        }

        return ans;
    }
};
