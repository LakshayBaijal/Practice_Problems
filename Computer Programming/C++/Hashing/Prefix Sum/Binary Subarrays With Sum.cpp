class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }   
        unordered_map<int,int>mp;
        mp[0] = 1;
        int total = 0;
        for(int i = 0;i<n;i++)
        {
            int minus = prefix[i] - goal;
            if(mp.count(minus))
            {
                total +=mp[minus];
            }
            mp[prefix[i]] ++;
        }
        return total;
    }
};
