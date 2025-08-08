class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;

        int maximum = nums[0];
        int minimum = nums[0];
        int result  = nums[0];

        for (int i = 1; i < n; ++i) {
            int x = nums[i];

            if (x < 0) swap(maximum, minimum);    

            maximum = max(x, maximum * x);     
            minimum = min(x, minimum * x);

            result = max(result, maximum);
        }
        return result;
    }
};
