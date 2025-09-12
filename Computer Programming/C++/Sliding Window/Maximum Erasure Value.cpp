class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
       unordered_map<int,int>dp;


       int lenght = 0;
       int right = 0;
       int left = 0;
       int total = 0;
       int maximum = 0;
       for(right = 0;right<nums.size();right ++)
       {
            total += nums[right];
            dp[nums[right]]++;

            while(dp[nums[right]] > 1)
            {
                dp[nums[left]] --;
                total -= nums[left];
                left++;
            }

            maximum = max(maximum,total);
       }

       return maximum;

       return maximum;
    }
};
