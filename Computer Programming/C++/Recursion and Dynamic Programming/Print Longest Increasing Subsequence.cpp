vector<int> getLIS(vector<int>& arr) 
    {
        // Code here
        
        int n = arr.size();
        vector<int>dp(n,1);
        vector<vector<int>>LIS(n);
        
        for (int i = 0; i < n; i++) 
        {
            LIS[i].push_back(arr[i]);
        }
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(arr[i] > arr[j])
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        LIS[i] = LIS[j]; 
                        dp[i] = dp[j] + 1;
                        LIS[i].push_back(arr[i]);
                    }
                }
            }
        }
        
        int index = 0;
        for(int i = 0;i<n;i++)
        {
            if(dp[i] > dp[index])
            {
                index = i;
            }
        }
        
        return LIS[index];
        
    }
