class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long n = nums.size();
        unordered_map<int,int>mp;
        long long total = 0;
        long long right = 0;
        long long left = 0;
        long long maximum = 0;
        for(right = 0;right < n;right++)
        {

            while (mp.count(nums[right])) 
            {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) 
                {
                    mp.erase(nums[left]);
                }
                total -= nums[left];
                left++;
            }

            mp[nums[right]] ++;

            total += nums[right];
            if(right - left + 1 > k)
            {
                mp[nums[left]] --;
                if(mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                }
                total -= nums[left];
                left ++;
            } 


            

            if(right - left + 1 == k)
            {
                maximum = max(maximum,total);
            }

        }    
        return maximum;
    }
};
