class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int total = 0;
        int ans = function(nums,target,n-1);
        return ans;
    }

    int function(vector<int>&nums, int target,int index)
    {
        if(index<0 && target == 0)
        {
            return 1;
        }
        if(index<0)
        {
            return 0;
        }

        int plus = function(nums,target + nums[index],index-1);
        int minus = function(nums,target - nums[index],index-1);

        return plus + minus;
    }
};
