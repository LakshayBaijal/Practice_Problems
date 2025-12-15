class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) 
    {
        unordered_map<int,int>mp;

        for(auto it : nums)
        {
            mp[it] ++;
        }    
        int n = 0;
        for (auto p : mp) {
            if (p.second == 2) {
                n ^= p.first;
            }
        }
        return n;
    }
};
