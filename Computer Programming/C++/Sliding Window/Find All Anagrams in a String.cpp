class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpp;
        
        for(auto it : p)
        {
            mpp[it] ++;
        }

        int left = 0;
        int right = 0;
        vector<int>ans;
        for(int right = 0;right<s.size();right++)
        {
            mps[s[right]] ++;
            if(right - left + 1 > p.size())
            {
                mps[s[left]] --;
                if(mps[s[left]] == 0)
                {
                    mps.erase(s[left]);  
                }    
                left ++;
            }

            if(right - left + 1 == p.size())
            {
                if(mpp == mps)
                {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};
