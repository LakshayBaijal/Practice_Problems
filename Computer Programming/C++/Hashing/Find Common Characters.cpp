class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        unordered_map<char,int> mp;

        string s = words[0];
        for(auto it : s)
        {
            mp[it]++;
        }

        for(int i = 1;i<words.size();i++)
        {
            unordered_map<char,int> mp_temp;
            for(auto it : words[i])
            {
                mp_temp[it] ++;
            }

            for(auto &it : mp)
            {
                if(mp_temp.count(it.first))
                {
                    it.second = min(it.second,mp_temp[it.first]);
                }
                else
                {
                    it.second = 0;
                }
            }
        }
        vector<string>ans;
        for(auto it : mp)
        {
            while(it.second>0)
            {
                ans.push_back(string(1,it.first));
                it.second --;
            }
        } 

        return ans;
    }
};
