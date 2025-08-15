class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n = nums.size();
        int total = 0;
        for(auto it:nums)
        {
            total += it;
        }
        int f0 = 0;
        for(int i = 0; i<n;i++)
        {   
            f0 = f0 + i*nums[i];
        }
        int maximum = f0;
        int temp = 0;
        for(int i = 1; i<n; i++)
        {
            temp = f0 + total - n*nums[n-i];
            maximum = max(maximum,temp);
            f0 = temp; 
        }

        return maximum;


    }
};
