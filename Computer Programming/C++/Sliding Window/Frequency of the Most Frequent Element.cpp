class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
         int right = 0;
         int left = 0;
         int n = nums.size();
         int maximum = 0;
         long long total = 0;
         sort(nums.begin(),nums.end());
         for(right = 0;right<n;right++)
         {
            total += nums[right];

            while(k + total < (long long) nums[right] * (right - left + 1))
            {
                total -= nums[left];
                left++;
            }

            maximum = max(maximum,right - left + 1);
         }   

         return maximum;
    }
};
