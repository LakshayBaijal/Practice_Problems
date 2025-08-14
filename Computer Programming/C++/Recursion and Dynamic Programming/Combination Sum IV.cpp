class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int n = nums.size();    

        vector<vector<int>> vis(n+1,vector<int>(target+1,-1));
        int ans = function(vis,nums,target,n-1);
        return ans;
    }

    int function(vector<vector<int>>&vis,vector<int>&nums,int target, int index)
    {
        int n = nums.size();
        if(target == 0)
        {
            return 1;
        }
        if(target < 0)
        {
            return 0;
        }

        if(index < 0)
        {
            return 0;
        }
        if(vis[index][target] != -1)
        {
            return vis[index][target];
        }

        int pick = function(vis,nums,target - nums[index],n- 1);
        int notpick = function(vis,nums,target,index-1);

        return vis[index][target] = pick + notpick;
    }
};
