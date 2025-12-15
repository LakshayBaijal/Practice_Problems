class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }    
        int count = 0;
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            

            int m = prefix[i] - k;
            if(m == 0)
            {
                count++;
            }
            if(mp.count(m))
            {
                count += mp[m];
            }
            mp[prefix[i]]++;
        }

        return count;
    }
};
