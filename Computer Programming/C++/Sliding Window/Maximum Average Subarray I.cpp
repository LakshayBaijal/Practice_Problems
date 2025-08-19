class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double  maximum = INT_MIN;
        double  total = 0;
        double  avg = 0;
        int right = 0;
        int left = 0;
        for(right = 0; right<nums.size();right++)
        {   
            total = total + nums[right];
            if(right - left + 1 == k)
            {
                avg = (double) total / k;
                total -= nums[left];
                left++;
                maximum = max(avg,maximum);

            }

        }

        return maximum;
    }
};
