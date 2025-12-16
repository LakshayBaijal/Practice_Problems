class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<long long>prefix(n);
        unordered_map<int,int>mp;
        prefix[0] = nums[0];
        mp[0] = -1;
        for(int i = 1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = 0;i<n;i++)
        {
            int m = ((prefix[i] % k) + k) % k; 
            if(mp.count(m))
            {
                if(i - mp[m] > 1)
                {
                    return true;
                }
            }
            else
            {
                    mp[m] = i;
            }
            
        }

        return false;
    }
};
