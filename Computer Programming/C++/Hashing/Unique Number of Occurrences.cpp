class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int> hash;
        unordered_map<int,int> freq;
        for(auto it : arr)
        {
            hash[it] ++;
        }   

        for(auto it : hash)
        {
            freq[it.second] ++;
            if(freq[it.second] > 1)
            {
                return false;
            }
        }
        return true;
    }
};
