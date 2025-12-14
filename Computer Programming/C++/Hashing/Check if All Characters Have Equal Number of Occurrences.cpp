class Solution {
public:
    bool areOccurrencesEqual(string s) 
    {
        unordered_map<char,int> hash;
        for(auto it : s)
        {
            hash[it] ++;
        }    
        int previous = hash[s[0]];
        for(auto it : s)
        {
            if(hash[it] != previous)
            {
                return false;
            }
        }
        return true;
    }
};
