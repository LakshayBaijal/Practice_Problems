class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1;i < n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }    

        mp[0] = 1;
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            int diff = prefix[i] - k;

            if(mp.count(diff))
            {
                count = count + mp[diff];
            }

            mp[prefix[i]] ++;
        }

        return count;
    }
};
