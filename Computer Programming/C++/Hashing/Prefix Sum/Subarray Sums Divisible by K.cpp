class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<int>prefix(n);
        prefix[0] = nums[0];
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int i = 1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            int mod = ((prefix[i] % k) + k) % k;
            if(mp.count(mod))
            {
                count += mp[mod];
            }
            mp[mod] ++;
        }

        return count;
        



    }
};
