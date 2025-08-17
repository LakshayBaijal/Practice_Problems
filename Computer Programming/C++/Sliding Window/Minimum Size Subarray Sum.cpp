class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0;
        int right = 0;

        int minlen = INT_MAX;
        int total = 0;

        for(right = 0; right<n;right++)
        {
            if(target>total)
            {
                total += nums[right]; 
            }

            while(target<=total)
            {
            int len = right - left + 1;
            minlen = min(len,minlen);
                total -= nums[left];
                left ++;
            }


        }    
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};
