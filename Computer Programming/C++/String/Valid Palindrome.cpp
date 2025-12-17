class Solution {
public:
    bool isPalindrome(string s) 
    {
        string cleaned = "";
        for(int i = 0;i<s.size();i++)
        {
            if(isalnum(s[i]))       
            {
                cleaned += tolower(s[i]); 
            }
        }

        string r = cleaned;
        reverse(r.begin(),r.end());

        if(cleaned==r)
        {
            return true;
        }    
        return false;
    }
};
