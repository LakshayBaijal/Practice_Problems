class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int left = 0;
        int right = 0;
        int n = nums.size();
        long long count = 0;
        long long total = 0;

        for(int right = 0;right < n;right ++)
        {
            total += nums[right];

            while((k <= total * (right - left + 1)))
            {
                
                total -= nums[left];
                left++;
            }

            count = count + right - left + 1;


        }

        return count;

    }
};
