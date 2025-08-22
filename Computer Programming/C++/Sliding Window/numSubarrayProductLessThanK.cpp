class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int left = 0;
        int right = 0;
        int count = 0;
        int product = 1;
        int n = nums.size();

        for(right = 0;right<n;right++)
        {
            product *= nums[right];

            
            while(product>=k && right >=left)
            {
                product /= nums[left];
                left++;
            }
            if(product<k)
            {
                count += right - left + 1;
            }
        }

        return count;
            
    }
};
