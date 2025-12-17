class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<int,int> mps;
        unordered_map<int,int> mpt;

        for(auto it : s)
        {
            mps[it] ++;
        }    
        for(auto it : t)
        {
            mpt[it] ++;
        }

        if(mps == mpt)
        {
            return true;
        }
        return false;
    }
};
