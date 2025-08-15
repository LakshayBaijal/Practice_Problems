class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        return {left(nums,target) , right(nums,target)};
    }

    int left(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int ans = -1;
        while(left<=right)
        {
            mid = (left + right)/2;
            
            if(nums[mid] >= target)
            {   
                if(nums[mid] == target)
                {
                    ans = mid;
                }
                right = mid-1;
            }

            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }

    int right(vector<int>& nums,int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int ans = -1;


        while(left <= right)
        {
            mid = (left + right)/2;
            if(nums[mid] <= target)
            {
                if(nums[mid] == target)
                {
                    ans = mid;
                }
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            
        }

        return ans;
    }



};
