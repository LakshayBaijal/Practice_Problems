class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        unordered_map<int,int>hash;
        for(auto it : nums)
        {
            hash[it] ++;
        }    
        vector<int> ans;
        for(auto it : nums)
        {
            if(hash[it] > 1)
            {
                ans.push_back(it);
                hash[it] = 0;
            }
        }
        return ans;
    }
};
