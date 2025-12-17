class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int n = s.size();
        unordered_set<string>sp;

        for(int i = 0; i + k <= n;i++)
        {
            sp.insert(s.substr(i,k));
        }

        int ans = sp.size();
        if(pow(2,k) == ans)
        {
            return true;
        } 
        return false;

    }
};
