class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        long long n = nums.size();
        unordered_map<long long,long long>mp;
        for(long long i = 0;i<n;i++)
        {
            long long minus = nums[i] - i;
            mp[minus]++;
        }    

        long long good_pairs = 0;
        for(auto it : mp)
        {
            long long c = it.second;
            good_pairs += (c*(c-1)) / 2;
        }

        long long total_pairs = (n * (n-1)) / 2;

        return total_pairs - good_pairs;
    }
};
