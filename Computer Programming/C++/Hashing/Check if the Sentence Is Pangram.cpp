class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        unordered_map<int,int> mp;

        for(auto it : sentence)
        {
            mp[it - 'a'] ++;
        }    

        for(int i = 0;i<=25;i++)
        {
            if(mp[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
};
