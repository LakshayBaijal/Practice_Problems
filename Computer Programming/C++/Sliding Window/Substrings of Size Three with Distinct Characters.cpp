class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        unordered_map<char,int>mp;

        int right = 0;
        int left = 0;
        int count = 0;
        for(int right = 0;right<s.size();right++)
        {
            int flag = 0;
            mp[s[right]] ++;
            if(right - left + 1> 3)
            {
                mp[s[left]] --;
                left++;
            }
            if(right - left + 1 == 3)
            {
                if(mp[s[left]] == 1 && mp[s[left+1]] == 1 && mp[s[left+2]] == 1)
                {
                    count++;
                }
            }
        }    
        return count;
    }
};
