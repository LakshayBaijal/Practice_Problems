class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        vector<int>odd;
        vector<int>even;
        vector<int>ans;
        for(auto it : nums)
        {
            if(it % 2 == 0)
            {
                even.push_back(it);
            }
            else
            {
                odd.push_back(it);
            }
        }
        int o = 0;
        int e = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(i%2 != 0)
            {
                ans.push_back(odd[o]);
                o++;
            }
            else
            {
                ans.push_back(even[e]);
                e++;
            }
        }

        return ans;
        
    }
};
