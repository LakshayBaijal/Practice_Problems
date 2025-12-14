class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int total = 0;
        unordered_map<int,int> mp;

        for(auto it : nums)
        {
            mp[it] ++;
            if(mp[it] > 1)
            {
                total += mp[it] - 1;
            }
        }    

        return total;
    }
};
