class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>sum(n,0);
        int max = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            int k = 0;
            int temp = 0;
            for(int j = 0;j<n;j++)
            {
                k = (i + j + n) % n;
                temp = k * nums[j] + temp;
            }

            if(temp > max)
            {
                max = temp;
            }
        }

        return max;

    }
};
