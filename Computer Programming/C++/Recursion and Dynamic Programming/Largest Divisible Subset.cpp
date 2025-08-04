class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> dp(n,-1);
        vector<int> prev(n,-1);
        int maxindex = 0;
        for(int i = 1; i<n;i++)
        {
            for(int j = 0; j<i;j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if(dp[i] > dp[maxindex])
            {
                maxindex = i;
            }
        }

        vector<int> result;
        while(maxindex != -1)
        {
            result.push_back(nums[maxindex]);
            maxindex = prev[maxindex];
        }
        reverse(result.begin(),result.end());

        return result;




    }
};
