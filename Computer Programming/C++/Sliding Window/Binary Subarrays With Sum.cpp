class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
       return function(nums,goal) - function(nums,goal-1);
    }

    int function(vector<int>&nums,int goal)
    {
        if(goal < 0)
        {
            return 0;
        }
        int right = 0;
        int left = 0;
        int n = nums.size();
        int ans = 0;
        int total = 0;
        for(right = 0;right<n;right++)
        {
            total +=nums[right];
            
            while(total>goal && right>=left) 
            {
                total -= nums[left];
                left++;
            }
                ans += right - left + 1;

        }    

        return ans;
    }
};
