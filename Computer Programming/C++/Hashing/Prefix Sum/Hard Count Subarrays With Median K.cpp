class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>transformed(n);
        int index = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] == k)
            {
                index = i;
                break;
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(i<index)
            {
                transformed.push_back(-1);
            }
            if(i == index)
            {
                transformed.push_back(0);
            }
            if(i>index)
            {
                transformed.push_back(1);
            }
        }

        unordered_map<int,int>mp;

        int balance = 0;

        for(int i = index; i<n;i++)
        {
            if(nums[i] < k)
            {
                balance --;
            }
            if(nums[i] > k)
            {
                balance ++;
            }

            mp[balance] ++;
        }
        balance = 0;
        int ans = 0;
        for(int i = index;i>=0;i--)
        {
            if(nums[i] < k)
            {
                balance --;
            }
            if(nums[i] > k)
            {
                balance ++;
            }

            ans += mp[-balance];
            ans += mp[1-balance];
        }

        return ans;






    }
};
