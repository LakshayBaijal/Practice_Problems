class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(auto it : s1)
        {
            mp1[it] ++;
        }    

        int right = 0;
        int left = 0;
        int s1_size = s1.size();
        int s2_size = s2.size();
        for(int right = 0;right<s2_size;right++)
        {
            mp2[s2[right]] ++;
            if(right - left + 1 > s1_size)
            {
                mp2[s2[left]] --;
                if(mp2[s2[left]] == 0)   // 🔥 IMPORTANT FIX
                    mp2.erase(s2[left]);
                left++;
            }

            if(right - left + 1 == s1_size)
            {
                if(mp2 == mp1)
                {
                    return true;
                }
            }            

        }

        return false;
    }
};
