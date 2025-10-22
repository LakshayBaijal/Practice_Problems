class Solution {
  public:
    int maxSumIS(vector<int>& arr) 
    {
        // Your code goes here
    
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>total(n);
        
        for(int i = 0;i<n;i++)
        {
            total[i] = arr[i];
        }
        
        for(int i = 1; i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    if(total[i] < total[j] + arr[i])
                    {
                    
                        total[i] = arr[i] + total[j];
                    }
                }
            }
        }
        int maximum = *max_element(total.begin(),total.end());
        
        return maximum;
    }
};
