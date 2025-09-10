class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>ans(n,-1);

        double total = 0;

        int right = 0; 
        int left = 0;

        for(right = 0;right<n;right++)
        {
            total += nums[right];

                if(right - left + 1 > 2*k + 1)
                {
                    total -= nums[left];
                    left++;
                }
             
                if (right - left + 1 == 2 * k + 1)
                {
                    int mid = left + k;
                    ans[mid] = total/(2*k+1);
                }
        }

        return ans;
    }
};
