class Solution {
public:
    string longestPalindrome(string s) 
    {
        int maxlen = 1;
        int start = 0;
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 1; j<=i && j+i<n;j++)
            {
                if(s[i-j]==s[i+j])
                {
                    if(2 * j + 1 > maxlen)
                    {
                        maxlen = 2 * j + 1;
                        start = i - j;
                    }
                }
                else
                {
                    break;
                }
            }
        }    

        for(int i = 0;i<n - 1;i++)
        {
            if(s[i] == s[i+1])
            {
                if(maxlen < 2)
                {
                    start = i;
                    maxlen = 2;
                }
            for(int j = 1;j<=i && i + j + 1 < n;j++)
            {
                if(s[i-j]==s[i+j + 1])
                {
                    if(2 * j + 2 > maxlen)
                    {
                        maxlen = 2 * j + 2;
                        start = i - j;
                    }
                }
                else
                {
                    break;
                }
            }
            }
        }

        return s.substr(start,maxlen);
    }
};
