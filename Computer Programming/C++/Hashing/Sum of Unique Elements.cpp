class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map<int,int> hash;
        for(auto it : nums)
        {
            hash[it] ++;
        }    
        int total = 0;
        for(auto it : nums)
        {
            if(hash[it] == 1)
            {
                total += it;
            }
        }

        return total;
    }
};
