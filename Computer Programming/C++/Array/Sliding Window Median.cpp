class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<double>median;
        
        for (int i = 0; i + k <= n; i++)
        {
            vector<double>window;

            for (int j = i; j < i + k; j++) 
            {
                window.push_back(nums[j]);
            }
                sort(window.begin(),window.end());

                if(k % 2 == 0)
                {
                    double total = (window[0 + k/2] + window[0 + k/2 - 1])/2;    
                    median.push_back(total);
                }
                if(k % 2 != 0)
                {
                    double total = window[0 + k/2];
                    median.push_back(total);
                }
                
            }
            return median;
        }

        

};
