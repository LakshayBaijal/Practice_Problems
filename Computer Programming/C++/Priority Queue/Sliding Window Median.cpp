class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        vector<double>ans;
        for(int right = 0;right < n;right ++)
        {
            if(right - left + 1 == k)
            {
                double med = function(nums,right,left);
                ans.push_back(med);  
                left++;     
            }
            
        }    

        return ans;
    }

    double function(vector<int>&nums,int right,int left)
    {
        priority_queue<int>pq;
        for(int i = left; i<=right;i++)
        {
            pq.push(nums[i]);
        }
        int size = right-left+1;
        if(size % 2 != 0)
        {
            for(int i = 0; i < size/2; i++)
                pq.pop();

            return pq.top();

        }

        else
        {
            for(int i = 0; i < size/2 - 1; i++)
                pq.pop();

            double l = pq.top();
            pq.pop();
            double r = pq.top();
            return (l+r) / 2.0;
        }

    }
};
